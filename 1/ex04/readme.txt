Sed is for losers

入出力ファイルストリームクラス
std::ifstream std::ofstreamで管理できる
それぞれコンストラクタで引数のファイルにアクセスできる ofstreamはstring型の引数に対応していないためc_strで型変換する必要がある

使用した関数

std::cerr		C++標準エラー出力ストリーム stderrみたいなもん

std::ifstream		入力ファイルストリームクラス ファイルからデータを読み込む
			std::ifstream	inFile(av[1]); のように使う

std::ofstream		出力ファイルストリームクラス ファイルにデータを書き込む
			std::ofstream	outFile(outFileName.c_str()); のように使う

str.c_str()		stringのデータを(const char*)として取得
			C++98ではofstreamクラスがstd::stringを直接受け取るコンストラクタがない
			そのためoutFileNmae.c_str()でC文字列に変換する必要がある

str.find(s1, pos)	str内でs1をposから検索し 最初に見つかった位置のインデックスを返す
			見つからなかったらnposを返す

std::string::npos	string::size_type型の最大値 find系の関数で見つからなかったことを示す
			if (pos == std::string::npos) つまり見つからなかったらということ

str.erase(pos, del)	strのpos位置からdel文字分削除
			std::string	s = "abcdef";
			s.erase(2, 3); => "abf"

str.insert(pos, add)	strのpos位置に文字列addを挿入
			std::string	s = "fuck";
			s.insert(4, " you!"); => "fuck you!"

inFile.eof()		ストリームのEOF状態を返す 読み取りがファイルの終端に達した場合はtrueを返す
