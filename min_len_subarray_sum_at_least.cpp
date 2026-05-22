#include<iostream>
#include<algorithm>

using namespace std;

int min_len_subarray_sum_at_least(int target, const int* arr, int size)
{
    int left = 0;
    int sum = 0;
    int ans = size + 1; // 代表“还没找到”

    for (int right = 0; right < size; ++right)
    {
        sum += arr[right];

        while (sum >= target)
        {
            ans = std::min(ans, right - left + 1);
            sum -= arr[left];
            ++left;
        }
    }

    return (ans == size + 1) ? 0 : ans;
}

int main()
{
    int nums[]={2,3,1,2,4,3};
    int target = 7;

    cout<<min_len_subarray_sum_at_least(target,nums,6)<<endl; //2, 4+3=7

}

/*
🚀 场景一：极速风控 —— “微爆流（Micro-burst）”极限探测
1. 网络 Infra 背景：
在极速交易网络中，交换机和网卡最怕的不是“平均流量大”，而是“微爆流（Micro-burst）”。
可能在 1 秒钟内，总数据量只有 10MB，交换机完全扛得住；但如果这 10MB 的数据，是集中在 10 微秒内瞬间砸过来的，交换机的底层硬件缓存（Buffer）就会瞬间被打穿，导致丢包。

2. 你的代码完美落地：
网络工程师需要复盘：“这 10MB（target）的数据量，在历史上最快是几微秒内聚集的？”

target = 10MB（触发交换机丢包的临界体积）。

arr = 每一微秒网卡接收到的字节数。

ans = 凑够 10MB 所经历的最短微秒数。

你的 right 指针在拼命接收数据包（sum += arr[right]）。一旦总包量达到了 10MB 的危险水位，你的 left 指针就开始疯狂往右收缩，寻找那个最致命的、时间最短的“爆炸区间”。
如果算出来的 ans 是 3（微秒），网络团队立刻就知道：我们遇到了极端微爆流，必须调整交换机的 Buffer 策略或开启流量整形（Traffic Shaping）。

📈 场景二：量化策略 —— “毒性订单流（Toxic Flow）”预警
1. 交易背景：
做市商（Market Maker）在盘口挂着买单和卖单。他们最怕遇到拿着内幕消息、或者带着几百亿资金来“扫货”的机构大鳄。大鳄为了抢筹码，会不计成本地以市价单砸盘，瞬间吃掉订单簿上所有的挂单。

2. 探测逻辑：
策略研究员要把大鳄抓出来。大鳄的特征是：在极其短暂的时间内，成交了极其巨大的单量。

target = 500 手（大单阈值）。

arr = 连续每一笔逐笔成交的数量。

ans = 成交这 500 手，最少用了几笔订单？

如果发现凑够 500 手需要 200 笔订单（ans = 200），说明是散户在慢慢买，市场很安全。
如果发现凑够 500 手，仅仅用了 2 笔订单（ans = 2）！这说明有机构在暴力扫单（Toxic Flow）。风控网关必须在纳秒级触发熔断，立刻撤下我们自己的单子，防止被大鳄“碾压”。
*/