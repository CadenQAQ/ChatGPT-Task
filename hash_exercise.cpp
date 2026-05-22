#include<iostream>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

/*
题 1：判断数组中是否存在重复元素

输入：

[1,2,3,4,5]
[1,2,3,1]

要求：
返回 true / false

*/
int a[5] = {1,2,3,4,5};
int b[4]={1,2,3,1};
int arr[] = {4,1,2,1,2};

/*1. has_common_element (集合求交集)
1. Infra 人的本能联想：
权限校验或路由黑白名单。比如查一个来源 IP 是否在我们的恶意 IP 资源池里。

2. 量化真实场景落地：自成交拦截 (Self-Match Prevention, SMP)
在交易所规则中，严禁同一个实控人的账户之间发生买卖撮合（这叫“对倒”或“洗盘 Wash Trade”，是违法行为）。

假设你的一台服务器上跑了多个策略，策略 A 想买腾讯，策略 B 想卖腾讯。

在订单发往交易所之前，你的风控系统（Risk System）必须做一个极速检查：买方关联账户组 (arr1) 和 卖方关联账户组 (arr2) 是否有交集？

如果 has_common_element 返回 true，风控系统必须直接把这两笔订单在本地拦截（Reject），绝对不能发出去。*/
template<size_t N1, size_t N2>
bool has_common_element(int (&arr1)[N1], int (&arr2)[N2])
{
    unordered_set<int> s1(arr1, arr1 + N1);
    /*传的不是两个数组，而是告诉 unordered_set：“从 arr1 这个内存地址开始读，一直读到 arr1 + N1 这个内存地址为止，把路上的所有数据都吸进去。” 
    这是一个极其优雅且底层的 C++ 惯用法。*/
    
    for(auto v: arr2)
    {
        if (s1.count(v) > 0)  // 如果arr2中的元素在s1中存在
        {
            return true;       // 发现有共同元素
        }
    }
    
    return false;  // 没有共同元素
}

/*性能极客视角 (Hot Path 终极魔改)：你现在的代码用的是 unordered_map 进行词频统计，这虽然是 $O(N)$ 的时间复杂度，但在量化大佬眼里，它太慢了，
且浪费了 $O(N)$ 的堆内存。极致魔改：对于这种“其他都出现偶数次，只有一个出现奇数次”的数据特征，
在底层 Infra 中，标准的解法是使用 按位异或 (XOR, ^) 操作！原理：两个相同的数字异或结果为 0（A ^ A = 0），任何数字和 0 异或还是它本身（A ^ 0 = A）。
优化后的代码，完全不需要 Map，0 内存分配，对 CPU 缓存极其友好，甚至能被编译器自动向量化（SIMD）优化：*/

/*
int single_num_optimized(const int *arr, size_t n) {
    int result = 0;
    for(size_t i = 0; i < n; ++i) {
        result ^= arr[i]; // 一路异或过去，成对的数字互相抵消为0
    }
    return result; // 活到最后的，就是那个唯一的数字
}
*/



/*
幂等性校验（Idempotency）。比如确保同一个 UUID 的 HTTP 请求或者消息队列（MQ）的消息不被重复处理。

2. 量化真实场景落地：行情 A/B 线双发去重 (A/B Line Arbitration)
为了追求极致稳定和速度，交易所发出的 UDP 行情数据，通常会通过两根物理光纤（A 线和 B 线）同时发给量化机构。

你的网卡可能会在第 1 微秒收到 A 线的 [消息序号 1024]，在第 1.5 微秒收到 B 线的 [消息序号 1024]。

你的行情解码器（Market Data Decoder）必须疯狂地调用类似 has_duplicate 的逻辑，把后到的重复包直接丢弃，保证只把最新、唯一的价格推送给策略。
*/
bool has_duplicate(const int* arr, size_t n)
{
    unordered_set<int> s1;

    for(size_t i = 0;i<n;++i)
    {
        if(s1.count(arr[i])>0)
        {return true;}

        s1.insert(arr[i]);
    }
    return false;
}


/*
1. Infra 人的本能联想：
连接状态的配对查找。比如在 TCP 握手/挥手日志中，找出那个发了 SYN 但没有收到 ACK 的孤儿连接。

2. 量化真实场景落地：订单对账系统 (Order Reconciliation / Drop Copy)
你的交易系统每天要发几百万笔订单（Order），交易所会回复对应的执行回报（Execution Report）。
正常情况下，每一个 Order ID 都必须对应一个 Execution ID（成对出现）。

在盘中或者收盘后的风控对账环节，你需要快速找出来：哪一笔订单发出去之后，交易所完全没有理我？（也就是所谓的“掉单”）。

这就是那个唯一的 single_num。
*/
int single_num(const int *arr, size_t n)
{
    int result=0;
    unordered_map<int, int>m1;
    for(size_t i =0;i<n;++i)
    {
        m1[arr[i]]++;
    }

    for(const auto &v: m1)
    {
        if (v.second==1)
        result = v.first;
    }
    

    return result;
}

int main()
{
    cout << boolalpha;
    cout << "是否有共同元素: " << has_common_element(a,b) << endl;  // 输出 true
    cout << "a是否有重复元素: " << has_duplicate(a,5) << endl;
    cout << "a不重复的元素是: " << single_num(arr,5) << endl;
}