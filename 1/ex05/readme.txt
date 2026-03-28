Harl

メンバ関数ポインタ
今回はprivateの中に関数debug infoなどが存在する
そしてpublicにそれらを呼び出すためのcomplain(std::string level)がある
void	Harl::complain(std::string level)においてprivateメンバ関数にアクセスするためにメンバ関数ポインタを使用する

void	(Harl::* funcs[4])() =
{
	&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
};
Harl::*型 つまりメンバ関数ポインタ型のfuncs[4]を宣言しそこにdebug infoそれぞれのメンバ関数のアドレスを入れていく
funcsはHarl.hppに存在するメンバ変数ではないので注意 あくまでHarlクラスのメンバ関数にアクセスできるポインタを宣言している
つまりHarlクラスのメンバ関数へアクセスできるアドレスを入れる器

main.cppでharl.complainの引数とlevels[4]のどれかがヒットすればそれに適したprivateメンバ関数にアクセスしprivateメンバ関数を実行する
その際にどのインスタンスで実行するかが不明なのでthisを用いて今いるインスタンスからfuncsにアクセスする
(this->* funcs[i])();

thisとは今いるインスタンスを指し示すポインタ そのためアロー演算子->を使ってアクセスする必要がある
その上今回用意した器は*funcs[4] メンバ関数にアクセスできるアドレスを入れたものなので
(this->* funcs[i])()
