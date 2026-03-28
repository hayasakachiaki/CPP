Fixed

オーバーロード演算子
ex01でやったcoutのオーバーロードのようにオーバーロード演算子にもそれぞれ初期設定がある
特徴的なのがインクリメント デクリメントについて

Point&	operator++();       // Prefix increment operator.
Point	operator++(int);     // Postfix increment operator.

Point&	operator--();       // Prefix decrement operator.
Point	operator--(int);     // Postfix decrement operator.
このように前置と後置の違いがある
前置は変化した値を使用する必要があるため直接メンバ変数を変更し そのままそれを返す
後置は変化する前の値を使用する必要があるためコピーコンストラクタを呼び出し メンバ関数を変更した後に変化前にコピーしたクラスを返す

res = a + b + c
上の式は temp1 = a + b; temp1 + c; temp2 = temp1 + c;　という流れで成り立つ
以前の =演算子やcoutなどは連続した演算子を成り立たせるために参照型を用いて 実体は変わらずそこに新しく流し込む形式だった 
しかし四則演算では
res = a + b　などの際に参照型を用いたやり取りを行うとデータが破損してしまう
例えば上の式で言えば a(4) b(2)の場合
res = a + b...6
しかしaが6に変更されデータが壊れてしまう そのため四則演算は参照型ではなく新しいクラスを返却する データコストは参照型よりも重くなる

bit gap
_rawはint型の変数であり今回のFixedでは受け取ったvalueを_fractionalBits分左にシフトした値が入っている
それは_fractionalBits分の小数点の情報を確保するためであるが 今回の* /演算子の計算において それら同士を乗算 除算することがある
その場合 _fractionalBitsは8なので256倍したもの同士で計算が行われてしまうので オーバーフローを防ぐためにlong型の変数に一旦保存する必要がある

Linux環境ではintは32 longは64ビット
そのため今回の* /演算子の際にlong型のtmpを使用する
