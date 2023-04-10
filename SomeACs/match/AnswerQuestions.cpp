/*
## 题目描述

有 $n$ 位同学同时找老师答疑。每位同学都预先估计了自己答疑的时间。老师可以安排答疑的顺序，同学们要依次进入老师办公室答疑。

一位同学答疑的过程如下:

1. 首先进入办公室，编号为 $i$ 的同学需要 $s_{i}$ 毫秒的时间。

2. 然后同学问问题老师解答，编号为 $i$ 的同学需要 $a_{i}$ 毫秒的时间。

3. 答疑完成后，同学很高兴，会在课程群里面发一条消息，需要的时间可以忽略。

4. 最后同学收拾东西离开办公室，需要 $e_{i}$ 毫秒的时间。一般需要 $10$ 秒、$20$ 秒或 $30$ 秒，即 $e_{i}$ 取值为 $10000$、$20000$ 或 $30000$。

一位同学离开办公室后，紧接着下一位同学就可以进入办公室了。

答疑从 $0$ 时刻开始。老师想合理的安排答疑的顺序，使得同学们在课程群里面发消息的时刻之和最小。

## 输入格式

输入第一行包含一个整数 $n$，表示同学的数量。

接下来 $n$ 行, 描述每位同学的时间。其中第 $i$ 行包含三个整数 $s_{i}, a_{i}, e_{i}$，意义如上所述。

## 输出格式

输出一个整数，表示同学们在课程群里面发消息的时刻之和最小是多少。

## 样例 #1

### 样例输入 #1

```
3
10000 10000 10000
20000 50000 20000
30000 20000 30000
```

### 样例输出 #1

```
280000
```

## 提示

**【样例说明】**

按照 $1,3,2$ 的顺序答疑，发消息的时间分别是 $20000,80000,180000$ 。

**【评测用例规模与约定】**

对于 $30 \%$ 的评测用例, $1 \leq n \leq 20$ 。

对于 $60 \%$ 的评测用例, $1 \leq n \leq 200$ 。

对于所有评测用例, $1 \leq n \leq 1000,1 \leq s_{i} \leq 60000,1 \leq a_{i} \leq 1000000$, $e_{i} \in\{10000,20000,30000\}$ ，即 $e_{i}$ 一定是 $10000 、 20000 、 30000$ 之一。
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int qtime;
    int sumTime;
} Student;

vector<Student> stus;

bool cmp(Student s1, Student s2)
{
    return s1.sumTime < s2.sumTime;
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int time1, time2, time3;
        cin >> time1;
        cin >> time2;
        cin >> time3;
        Student s;
        s.qtime = time1 + time2;
        s.sumTime = s.qtime + time3;
        stus.push_back(s);
    }
    sort(stus.begin(), stus.end(), cmp);
    long ans = 0, time = 0;
    ans += stus[0].qtime;
    time += stus[0].sumTime;
    for (int i = 1; i < stus.size(); i++)
    {
        ans += (time + stus[i].qtime);
        time += stus[i].sumTime;
    }
    cout << ans;
    return 0;
}