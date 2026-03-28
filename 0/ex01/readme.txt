PhoneBook.cpp

void	set(const std::string& fn)
C++では参照型という新しい型がある 基本的に操作しないデータはconst string& sのように引き渡すことで
constの要素+参照型の特性(データをコピーせず直接中身を別変数と共有する)を利用し動作が軽くなる
参照型を宣言するときは代入も同時に行う必要がある
const Contact& c = _data[i];

Contact::Contact() {}
コンストラクタという概念 C++ではクラスそれぞれにコンストラクタを用意できる
クラスを呼び出したときに実行される関数のことで 例えば今回は
PhoneBook::PhoneBook() : _size(0), _next(0) {}
のように_size _nextをそれぞれ初期化している

メンバ関数とメンバ変数
クラスの中にpublic privateを用意できる
publicはほかの関数から操作可能でprivateはそのクラス自体しか操作できない
publicに関数を用意してprivateに変数を用意する
そのクラスで定義された関数 変数をそれぞれメンバ関数 メンバ変数と呼ぶ
クラスを宣言したブロックではそのクラスで定義されたメンバ関数とメンバ変数を使用することができる
pb.size() pb.printTable() など

void	printTable() const
C++ではクラスのなかにメンバ変数を設定できる
そのメンバ変数自体には干渉しないという明示がこのconst

使用した関数
var.size()			varのサイズがわかる strlen

std::getline(std::cin, s)	sの中にcinを代入する cinは空白を区切るのでgetlineを使用する

std::stringstream ss		ストリーム型の変数 ssを宣言しsで初期化する 宣言だけでも使える
				ssは出力入力どちらも兼ねている
				std::string		input;

				std::getline(std::cin, input); ..."fuck you!"
				std::stringstream	ss(input);

				int	a, b;
				ss >> a >> b;
				aに"fuck" bに"you!"が入る

std::ostringstream oss(s)	出力を受け取る専用のストリーム型の変数 ossを宣言しsで初期化する 宣言だけでも使える
				ossは使い方が奇妙で
				ストリームの中に出力していくことで変数を変化できる
				std::ostringstream	oss;
				oss << "fuck"; ossは"fuck"
				oss << " you!"; ossは"fuck you!"といった感じ
				今回はこのossにsetwを使用し更に追加で文字列を出力することでadjustに成功した

cout << std::setw(len)		len分の空きを確保する その次の出力をlenの右端に入れていく
				今回は10個分の欄でそこにデータを詰めていったのでadjust関数で使用した

var.substr(i, j)		varのindex iからj分を切り取って返却する

var.empty()			varがstrlen == 0だった場合にtrueを返す
