// 贝塔系数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
//求相关系数
double calculate(double arr1[], double average1, double arr2[], double average2, int n)
{
	double sum1=0.0, sum2=0.0, sum3=0.0;
	for (int i = 0; i < n; i++)
	{
		sum1 += ((arr1[i] - average1) * (arr2[i] - average2));
		double temp1, temp2;
		temp1 = (arr1[i] - average1);
		sum2 += pow(temp1, 2);
		temp2 = (arr2[i] - average2);
		sum3 += pow(temp2, 2);
	}
	double num1, num2;
	num1 = sqrt(sum2);
	num2 = sqrt(sum3);
	double result = sum1 / (num1*num2);
	return result;
}

//计算标准差
double standard_deviation(double arr[], double average,int n)
{
	double sum=0.0;
	for (int i = 0; i < n; i++)
	{
		double temp = (arr[i] - average);
		sum += pow(temp, 2);
	}
	double temp1 = sum / (1.0*n - 1.0);
	double result = sqrt(temp1);
	return result;
}

//计算贝塔系数
double beta(double num1, double num2, double num3)
{
	double result = num1 * (num2 / num3);
	return result;
}
int main()
{
	int n; // 年度数
	double *stockIncome, *marketIncome; // 股票收益和市场收益
	double stockSum = 0, marketSum = 0; // 求和
	double averageStock, averageMarket; // 股票收益和市场收益的年度平均数
	cout << "请输入一共有多少个年度的数据：";
	cin >> n;
	stockIncome = new double[n];
	marketIncome = new double[n];
	cout << "请输入每年度的股票收益和市场收益：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> stockIncome[i] >> marketIncome[i];
		stockSum += stockIncome[i];
		marketSum += marketIncome[i];
	}
	averageStock = 1.0 * stockSum / n;
	averageMarket = 1.0 * marketSum / n;
	// 求相关系数
	double correlation_ccoefficent = calculate(stockIncome, averageStock, marketIncome, averageMarket, n);
	cout << "该股票与市场的相关系数：" << correlation_ccoefficent << endl;
	//求标准差
	double num1 = standard_deviation(stockIncome, averageStock, n);
	double num2 = standard_deviation(marketIncome, averageMarket, n);
	cout << "股票的标准差：" << num1 << " 市场的标准差：" << num2 << endl;
	double result = beta(correlation_ccoefficent, num1, num2);
	cout << "该股票的贝塔系数：" << result << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
