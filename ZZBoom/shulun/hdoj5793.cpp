githug里的唯一一篇题解。。。自high最重要...

找出的规律。。。。
n m
1 2
3 
2 2
7
3 2
15
4 2
31
5 2
63

1 3
4
2 3
13
3 3
40
4 3
121
5 3
361
然后我们来推个公式： 
比如说a2=3a1+1，

我们可以看到 
等比是m, 
然后凑一下， 
1+x=m*x 
x=1/(m-1) 
上面那个例子就凑成了这个样子， 
(a2+1/2)/(a1+1/2)=3

所以首项是：m+1+[1/(m-1)] 
第n项是：[m+1+1/(m-1)]*m^(n-1) 
答案是：[m+1+1/(m-1)]*m^(n-1)-1/(m-1); 
那么答案就是：[m^(n+1)-1]/(m-1);

mdzz，我真蠢。 
巨巨加油~

23333333333,神队友去写然后wa了。。。。 
除法还要逆元，求逆元有两种方法，一个就是扩展欧几里得，另一个有点特殊，就是费马小定理。 
复习一下： 
因为取膜不适用与除法，所以当我们要求(a/b)mod p的时候呢，要拐个弯，求一下b的逆元，其实说白了，在算式里，小白理解就是他的倒数嘛。 
那么就是b*k=1;k=1/b; 
带入(a/b) mod p,就是(a*k)mod p,取膜适用乘法~好，我们来求逆元。 
算b的逆元k,k=1/b;我来转换一下，就是直接设成这样的，k=(px+1)/b;然后带到(a*k)mod p,得(a/b)mod p; 
那么就是直接求个k就好啦，然而 k=(p*x+1)/b;把 b 一移得 k*b-p*x=1;这种形式的不定方程？？？怎么求啊，exgcd… 
在exgcd中，k,x都是未知数，然后b,-p是常量，跑一跑exgcd就好啦。 
然后我再温习一下exgcd吧。 
首先给出适用条件，对于这种单纯利用exgcd的题，这个条件也是切入点啊。对于不定整数方程AX+BY=C，若 C mod gcd(A, B)=0,则该方程存在整数解，否则不存在 x , y 整数解。 
在我们这个求逆元环节中，A=b,B=-p,很明显在我们本道题里，p是1e9+7是素数，那么gcd就=1，所以满足。 
然后exgcd的推导？额。。。接下来会看的很烦，而且没有乘号但是。。我觉得读者在草稿纸上列个小公式会很清楚的。 
对于ax+by=gcd(a,b); 
我们设一下a>b,在简单直接把b=0时，gcd(a,b)=a.此时，x=1,y=0; 
接着，a>b>0，我们这里可以摆两个式子：①：ax1+by1=gcd(a,b);继续，②：bx2+(a mod b)y2=gcd( b , a mod b );第二个式子为何呢？这就是gcd的辗转相除法的算法啊。而且gcd(a,b)=gcd(b,a mod b); 
然后我们就能将gcd左边两个等式列个等式：ax1+by1=bx2+(a mod b)y2;额。。。a mod b可以写成？a-(a/b)b对吧，那么等式变成ax1+ by1= bx2+ (a - (a / b) * b)y2=bx2+ay2 - (a / b)by2 ;我们把ax1+ by1=bx2+ay2 - (a / b)by2拎出来，整理一下，写成：ax1+by1=ay2+b(x2-(a/b)y2); 那么很明显我们可以得到，x1=y2,y1=x2-(a/b)y2; 
这样我们就得到了求解 x1,y1 的方法：x1，y1 的值基于 x2，y2. 
然后跑的不就是gcd辗转相除法嘛，那么最后一个不定方程不就是b==0的时候return，那个时候x=1,y=0啊，正好递归回来给了前面的x1,y1,一直递归到最开始的不定方程的x1,y1.OK,讲完。 
还是自己再温习一个前面说的费马小定理， 
以下懒得打了，去某篇大牛blog选摘来的… 
费马小定理说，对于素数 M 任意不是 M 的倍数的 b，都有：b ^ (M-1) = 1 (mod M).直接拆成：b * b ^ (M-2) = 1 (mod M)。于是：a / b = a / b * (b * b ^ (M-2)) = a * (b ^ (M-2)) (mod M)，但是用费马小定理！！！首先的条件！！！！原blog没讲，mdzz。。。 
百度百科倾情奉献：费马小定理(Fermat Theory)是数论中的一个重要定理，其内容为： 假如p是质数，且gcd(a,p)=1，那么 a^(p-1)≡1（mod p）。刚好在本道题目一样适用，mod=1e9+7就是质数，那么gcd也就是=1，OK，那么b*k=1这个逆元k=b^(mod-2) = =好像就是这样。 
当当当当，看到这边的小伙伴将会得到本道题的最终答案(我知道没有。。。自high一下。。。)： 
[m^(n+1)-1]*(m-1)^(mod-2)

最终AC代码？自己写吧。。。一个快速幂，，，就好了。。。套个小公式而已，自己动手~丰衣足食~