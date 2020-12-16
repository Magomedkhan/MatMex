#include<cstdio>
#include<cmath>
int ten_deg(int deg) {
	int result = 1;
	for (int i = 0; i < deg; ++i) result *= 10;
	return result;
}

double func(double x, int m, double eps) {
	int i = 1;
	int k_i = 1;
	double lastresult = 0; double result = 0; double delta;
	double temp = 1.0;
	do {
		lastresult = result;
		k_i *= i;
		temp *= (x * (m - i + 1));
		result += (temp / k_i);
		(i)++;
		/*  разница  */
		if ((lastresult - result) >= 0) { delta = lastresult - result; }
		else { delta = result - lastresult; }
	} while (delta >= eps);
	return result;
}

double ln(double p, int m, int t) {
	double rr = 0;
	t++;
	double eps = 1.0 / ten_deg(t);
	rr = func(p, m, eps);
	return rr;
}

int main() {
	double x;
	int m;
	int t;
	scanf("%lf %d %d", &x, &m, &t);
	printf("%lf\n", pow(1 + x, m));
	printf("%lf\n", double(int((ln(x, m, t) + 1) * ten_deg(t))) / ten_deg(t));
	return 0;
}