Fixed

今回は型とビットについての理解課題

1 << _fractionalBits
これは1を_fractionalBits分左にシフトした数 つまり256
今回は小数点の情報を8ビットまで扱う

Fixed(const int value)
	_raw = value << _fractionalBits;
今回は_rawに引数valueの8ビット左シフトした情報を入力する
その_rawを都度変換することでint floatに対応したデータを出力できる

Fixed(const float value)
	_raw = (int)(roundf(value * (1 << _fractionalBits)));
floatは小数点を表すビットを持っている型で今回は8ビット分の小数点の情報は確保し それ以降は無視する
そのため8ビット分左にシフトしそれをint型にキャストすることで最低限の情報を持った_rawを確保できる

float	toFloat(void) const
	return ((float)_raw / (1 << _fractionalBits));
_rawには本来の数値を8ビット左シフトした数値が入っている それをfloatにキャストし256で割る
_rawには8ビット分の小数点の情報が入っているため右に8シフトするのと256で割るのとでは小数点の情報を扱えるか扱えないかの差が出る

int	toInt(void) const
	return (_raw >> _fractionalBits);
_rawには小数点の情報が8ビット分入っているがintはそれらを扱わないので右に8シフトする

std::ostream&	operator<<(std::ostream& os, const Fixed& raw)
{
	os << raw.toFloat();
	return (os);
}
<<演算子でFixedを受け取った場合のオーバーロード
Fixedをrawとして参照型で受け取り raw.toFloat()をosに流す それを返却する

使用した関数

roundf(f)	float型のfを四捨五入する
