#include <iostream>
using namespace std;

/*
int bmi_index() {
	int weight;
	cout << "Please enter your weight." << endl;
	cin >> weight;
	double height;
	cout << "Please enter your height." << endl;
	cin >> height;
	double bmi_index;
	bmi_index = weight / (height * height);
	cout << "Your bmi index is " << bmi_index << endl;
	return 0;
}

int download_speed() {
	cout << "What is your file size? (in MBs)" << endl;
	int file_size, file_size_new;
	cin >> file_size;
	file_size_new = file_size * 1024 * 1024 * 8;
	cout << "What is your download speed (in bits per second)?" << endl;
	int download_speed;
	cin >> download_speed;
	int download_time;
	int download_time_h, download_time_m, download_time_s, download_time_s_final;
	download_time = file_size_new / download_speed;
	download_time_h = download_time % 3600;
	download_time_s = download_time - download_time % 3600;
	download_time_m = download_time_s % 60;
	download_time_s_final = download_time - download_time_h * 3600 - download_time_m * 60;
	cout << "Your download should take " << download_time_h << "Hours, " << download_time_m << "Minutes and " << download_time_s_final << "seconds." << endl;
	return 0;
}

//bir bölme iþlemi float cinsindense fidelity yüksek olur.
//Ýntegerý integera bölersen sadece ama sadece integer alýrsýn.

int car_problem() {
	string location1;
	string location2;
	string closer_city;
	float distance;
	float velocity1;
	float velocity2;
	float meeting_point;
	float total_travel_time;
	cout << "Please enter the names of these locations" << endl;
	cin >> location1 >> location2;
	cout << "Please enter the velocities of the vehicles." << endl;
	cin >> velocity1 >> velocity2;
	cout << "Please enter the distance between " << location1 << " and " << location2 << endl;
	cin >> distance;
	total_travel_time = distance / (velocity1 + velocity2);
	meeting_point = total_travel_time * velocity1;
	closer_city = location1;
	if (velocity2 < velocity1) {
		closer_city = location2;
	}
	cout << "The vehicles should meet at " << meeting_point << "th kilometer of the road starting from" << closer_city << ", " << total_travel_time << "hours after they leave " << location1 << " and " << location2 << "." << endl;
	return 0;

}

int main() {
	float pizza1_price, pizza1_radius;
	float pizza2_price, pizza2_radius, bestprice;
	bestprice = pizza1_price;
	cout << "Enter the price and the radius of the 1st pizza." << endl;
	cin >> pizza1_price >> pizza1_radius;
	cout << "Enter the price and the radius of the 2nd pizza." << endl;
	cin >> pizza2_price >> pizza2_radius;
	if (pizza1_price / (pizza1_radius * pizza1_radius * 3.14) > (pizza2_price / (pizza2_radius * pizza2_radius * 3.14))) {
		bestprice = pizza2_price;
	}
	cout << "The pizza that costs " << bestprice << "is the best pizza." << endl;
	return 0;
}
*/