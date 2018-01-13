/*
This project asks me to Calculate a + b and output the sum in standard format -- that is,
the digits must be separated into groups of three by commas (unless there are less than four digits).
*/

#include "iostream"
#include "string"
#include "sstream"
using namespace std;

struct FormatAB
{
	int a, b;
	int sum;
	int getSum();
	void getFormat();
}Format;
int FormatAB::getSum() {
	cin >> Format.a;
	cin >> Format.b;
	sum = a + b;
	return sum;
}
void FormatAB::getFormat() {
	stringstream ss;
	int temp, len, sum, i=0;
	sum = Format.getSum();
	ss << sum;
	string str = ss.str();
	//cout << str << endl;
	//cout << typeid(str).name() << endl;
	len = str.length();
	temp = len % 3;
	if (sum >= 0 && len > 3) {
		cout << str.substr(i, temp);
		cout << ",";
		for (i = temp; i < len - 3 ; i=i+3) {
			cout << str.substr(i, 3);
			cout << ",";
		}
		//cout << str.substr(i, 3);
	}
	else if(sum < 0 && len > 3)
	{

		if (temp == 2 ) {
			cout << str.substr(i, temp);
			cout << ",";
		}
		if (temp == 1 || temp == 0) {
			temp = temp + 3;
			cout << str.substr(0, temp);
			cout << ",";
		}
		for (i = temp; len > 3 &&i < len - 3; i = i + 3) {
			cout << str.substr(i, 3);
			cout << ",";
		}
		
	}
	cout << str.substr(i, 3);
}
int main() {
	Format.getFormat();
	//system("pause");
	return 0;
}
