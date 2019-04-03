# sanmokunarabe

3×3の方眼紙に交互に'b', 'w'をうっていき,三個連続で自分のマークがうれてばそのマークの人の勝利です.

```
 ─├─├─
 ─├─├─
 ```

# Pattern match

先手:'b'
後手:'w'

全探索したあとそのファイルを元にパターンマッチングをする.

## 実行方法

```
mkdir build
cd build
cmake ..
make
./PatternMatch_make_file
./PatternMatch_main
```


# UCB1 algorithm

先手:'w'
後手:'b'

コンピュータ同士で戦うことで環境に即したルールを自分で作り上げる

## 実行方法

```
mkdir build
cd build
cmake ..
make
./UCB1_algorithm
```

