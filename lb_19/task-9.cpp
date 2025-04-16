#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string values_line;
    getline(cin, values_line);

    string template_line;
    getline(cin, template_line);

    map<string, string> values;
    stringstream ss(values_line);
    string pair;

    while (getline(ss, pair, ',')) {
        size_t pos = pair.find('-');
        if (pos != string::npos) {
            string name = pair.substr(0, pos);
            string value = pair.substr(pos + 1);
            values[name] = value;
        }
    }

    string result = template_line;
    size_t start_pos = 0;
    while ((start_pos = result.find('[', start_pos)) != string::npos) {
        size_t end_pos = result.find(']', start_pos + 1);
        if (end_pos != string::npos) {
            string name = result.substr(start_pos + 1, end_pos - start_pos - 1);
            if (values.find(name) != values.end()) {
                result.replace(start_pos, end_pos - start_pos + 1, values[name]);
                start_pos += values[name].length(); // Move start_pos past the replaced value
            } else {
                start_pos = end_pos + 1; // Move start_pos past the unknown placeholder
            }
        } else {
            start_pos++; // Move start_pos to avoid getting stuck
        }
    }

    cout << result << endl;

    return 0;
}
