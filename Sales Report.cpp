#include <iostream> // Includes the I/O stream library for input/output operations
#include <string>   // Includes the string library
#include <iomanip>  // Includes the iomanip library for input/output manipulation (like setw, setprecision)
#include <vector>   // Includes the vector library
#include <algorithm>// Includes the algorithm library for functions like sort, minmax_element

using namespace std; // Using the standard namespace

// Function prototypes
void printSalesReport(const vector<pair<string, double>>& sales);
void printSummary(const vector<pair<string, double>>& sales);
void printMovingAverage(const vector<pair<string, double>>& sales);
void printSortedSales(const vector<pair<string, double>>& sales);

int main() {
    // Sample sales data
    vector<pair<string, double>> sales = {
        {"January", 23458.01}, {"February", 40112.00}, {"March", 56011.85},
        {"April", 37820.88}, {"May", 37904.67}, {"June", 60200.22},
        {"July", 72400.31}, {"August", 56210.89}, {"September", 67230.84},
        {"October", 68233.12}, {"November", 80950.34}, {"December", 95225.22}
    };

    // Print the reports
    cout << "Monthly sales report for 2022:" << endl;
    printSalesReport(sales);

    cout << "\nSales summary:" << endl;
    printSummary(sales);

    cout << "\nSix-Month Moving Average Report:" << endl;
    printMovingAverage(sales);

    cout << "\nSales Report (Highest to Lowest):" << endl;
    printSortedSales(sales);

    return 0; // Returns 0 to indicate successful execution
}

void printSalesReport(const vector<pair<string, double>>& sales) {
    for (const auto& sale : sales) { // Iterates over each sale
        cout << left << setw(10) << sale.first << " $" << right << setw(10) << fixed << setprecision(2) << sale.second << endl;
    }
}

void printSummary(const vector<pair<string, double>>& sales) {
    auto minmax = minmax_element(sales.begin(), sales.end(),
                                 [](const pair<string, double>& a, const pair<string, double>& b) {
                                     return a.second < b.second;
                                 }); // Finds the min and max sales
    double total = 0;
    for (const auto& sale : sales) {
        total += sale.second; // Sums up all sales
    }
    double average = total / sales.size(); // Calculates the average sales

    cout << "Minimum sales: $" << fixed << setprecision(2) << minmax.first->second << " (" << minmax.first->first << ")" << endl;
    cout << "Maximum sales: $" << fixed << setprecision(2) << minmax.second->second << " (" << minmax.second->first << ")" << endl;
    cout << "Average sales: $" << fixed << setprecision(2) << average << endl;
}

void printMovingAverage(const vector<pair<string, double>>& sales) {
    for (size_t i = 0; i < sales.size() - 5; ++i) { // Iterates through the sales for moving averages
        double sum = 0;
        for (size_t j = i; j < i + 6; ++j) {
            sum += sales[j].second; // Sums six consecutive months of sales
        }
        double avg = sum / 6; // Calculates the average of these six months
        cout << sales[i].first << " - " << sales[i+5].first << ": $" << fixed << setprecision(2) << avg << endl;
    }
}

void printSortedSales(vector<pair<string, double>> sales) {
    sort(sales.begin(), sales.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second > b.second; // Sorts the sales in descending order
    });
    for (const auto& sale : sales) { // Iterates over the sorted sales
        cout << left << setw(10) << sale.first << " $" << right << setw(10) << fixed << setprecision(2) << sale.second << endl;
    }
}