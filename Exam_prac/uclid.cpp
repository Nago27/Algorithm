// 분수의 덧셈 구하기
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){  // 유클리드 호제법 (최대공약수 구하기)
    if (b == 0){
        return a; // b가 0이면 a가 최대공약수
    }
    else return (b, a%b);
}

int main() {
    int numer1, numer2;
    int denom1, denom2;
    vector<int> answer;
    cin >> numer1 >> denom1 >> numer2 >> denom2;

    int num = numer1*denom2 + numer2*denom1;
    int denom = denom1 * denom2;

    int val = gcd(num, denom);

    answer.push_back(num / val);
    answer.push_back(denom / val);
}