#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>
#include <iostream>

class FileDescriptor {
private:
    int fd_{-1};

public:
    explicit FileDescriptor(const char* filename, int flags = O_RDONLY)
        : fd_(::open(filename, flags)) {
        if (fd_ == -1) {
            throw std::runtime_error("Failed to open file");
        }
    }

    // 可选：支持 O_CREAT 的重载（更工程化）
    FileDescriptor(const char* filename, int flags, mode_t mode)
        : fd_(::open(filename, flags, mode)) {
        if (fd_ == -1) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileDescriptor() noexcept {
        if (fd_ != -1) {
            ::close(fd_);
        }
    }

    FileDescriptor(const FileDescriptor&) = delete;
    FileDescriptor& operator=(const FileDescriptor&) = delete;

    FileDescriptor(FileDescriptor&& other) noexcept : fd_(other.fd_) {
        other.fd_ = -1;
    }

    FileDescriptor& operator=(FileDescriptor&& other) noexcept {
        if (this != &other) {
            if (fd_ != -1) {
                ::close(fd_);
            }
            fd_ = other.fd_;
            other.fd_ = -1;
        }
        return *this;
    }

    int get() const noexcept { return fd_; }
    bool isValid() const noexcept { return fd_ != -1; }

    // 可选：显式释放所有权（面试加分）
    int release() noexcept {
        int tmp = fd_;
        fd_ = -1;
        return tmp;
    }

    // 可选：重置为新的 fd
    void reset(int newfd = -1) noexcept {
        if (fd_ != -1) {
            ::close(fd_);
        }
        fd_ = newfd;
    }
};

int main() {
    FileDescriptor f1("test.txt", O_RDONLY);
    std::cout << "fd=" << f1.get() << "\n";

    FileDescriptor f2 = std::move(f1);
    std::cout << "f1 valid? " << f1.isValid() << "\n";
    std::cout << "f2 fd=" << f2.get() << "\n";
}