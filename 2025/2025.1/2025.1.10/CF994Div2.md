# CF994-Div2

今天继续来写Cf994.

## C
又是一个构造题,首先考虑不增添新的朋友关系的情况.假设n\==3,那么显然可以取0,1,2为各自的a;n\==4时,可以取0,1,0,1;n==5时,可以取0,1,0,1,2.怎么样,是不是发现规律了.实际上就是01依次循环,如果是奇数的话就在最后补一个2.现在考虑添加一对新的朋友关系会怎么样.

我们干脆以n\==5的情况为例子来试一下.假设二号和四号是朋友,那么可以取0,2,0,1,2.算了感觉还是n\==7好一点,n\==7在没增添新的朋友关系时为0,1,0,1,0,1,2.假设第二和四为朋友,那么就有可以取0,1,0,2,0,1,2;假设二和五为朋友,可以取0,1,0,1,0,1,2,也就是说没影响,到这里其实已经发现规律了吧,就是说新增朋友本来数字一样时就要把1改成2,把0改成2.最后一种情况,最后一个2参与了新的朋友关系,由于它只能和0或者1产生朋友关系,自己本身的朋友就是0和1,且0和1也不会被他干扰,所以就是没有任何影响.

忽略一种特殊情况,2旁边的数字参与新的朋友关系怎么办,假设一和五成为朋友,那么就有2,1,0,1,0,1,0.所以就是把第一个改为2,原本的2改为0就可以了.若六和二成为朋友,就有0,2,0,1,0,1,2,直接把较小的数字改了就可以.

nnd细节还是不少的,错了一发才过.感觉又花了我二十分钟啊,太菜了.今天有时间的话想去学一点花里胡哨的数据结构,下午还是去馆子吧.

## D
看了一下D题,感觉有点像wqs二分?先去吃饭吧.再看一眼,是dp吧.感觉就是一个三维的dp,去图书馆慢慢整吧.

到图书馆了,初步估计了一下,转移的复杂度大概是n^4数量级,太离谱了,得优化dp才可以.实际上可以优化为n^3,好了,开始写吧.1900分的题目呢.WA了一发,数据太大了超出0x3f3f3f3f3f,改成1e18做最大值就好了,以后一直1e18吧...

有一说一这个题1900是不是高了,作为1900分的题目这个思路也太显然了一点.

## E

这是2400的题目,不是我这种1500弱鸡可以碰瓷的嘤嘤嘤.以后再来做吧.其实2400的题倒也不是不能写,就是现在的水平写起来太累了,还是等自己实力达到了再来挑战.

刚刚学了一会CS61A,越学越困了,可能是我最近缺乏运动导致干什么事情都精力不足?冬天暖气开着又有点缺氧,脑子晕乎乎的.

看了一下这个题,是一个交互,显然是通过二分找答案的,核心问题是怎么确定这个1的位置在哪儿.我应该可以单杀.我的意思是我能被单杀,2400就是2400,还是别随便碰瓷了.我来康康题解.好复杂啊这题目,头晕晕的,也有可能是早上睡太久了导致的,睡到12点才起来.其实这种交互题就是构造的一种吧,得想到一种十分巧妙的查询才能符合次数的把结果搞出来.

真是太精巧的构造了,不知道是怎么想到的这么神的思路.不过我第一步确实想对了,就是要先确定1的位置,可是我没想到这么巧妙的方法,后面就是在巧妙利用题目的条件了,感觉是灵光一现的产物.不过这也是有迹可循的,毕竟次数限制的很死33次,只够一次二分,从这就可以往只做一次二分的方向上寻找突破口了.

写起来倒是很快的, 不过交互题验样例太麻烦了,我~~直接交了~~.错了四五发,下次还是想清楚再交吧,不然正赛又要成战犯了.今天的深绿目标也已经完成了,明天继续加油.要不要去学点数据结构呢.
## F


