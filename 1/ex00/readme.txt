Zombie.cpp

デストラクタ
クラスを設定するときにコンストラクタとは別に~Class();のように設定できる
デストラクタはインスタンスが破棄されるときに呼び出される そのためコンストラクタと同じように処理を設定できる
今回は cout << _name << " is destroyed" << endl; のようになっている

delete
freeに似ている Classで定義されたデストラクタを実行し ヒープ領域を解放する関数
new deleteのセット
今回はZombie* z1を用意し そこにnewで確保されたクラスを代入しているのでdeleteで解放する必要がある

Zombie*	newZombie(string name)
	return (new Zombie(name))
C++では
Class asd;
asd = new Class;
でヒープ領域でクラスを確保できる
そのため上の関数はZombie*を返却する
しかし newで返されたポインタは解放する義務があるのでdeleteを使わなければいけない

使用した関数

delete Class	Classで定義されているデストラクタを実行した後 newで確保されたClassを解放する
