#include <bits/stdc++.h>

using namespace std;

using ComprStr = pair<string, vector<int>>;

ComprStr compress(const string& str) {
    ComprStr ans;
    for (const char ch : str) {
        if (ans.first.empty() || ans.first.back() != ch) {
            ans.first += ch;
            ans.second.push_back(1);
        } else {
            ++ans.second.back();
        }
    }
    return ans;
}

bool is_subseq(ComprStr needle, ComprStr haystack) {
    for (int i = 0, j = 0; i < static_cast<int>(needle.first.size()); ++i) {
        while (needle.second[i] > 0) {
            while (j < static_cast<int>(haystack.first.size()) && (haystack.second[j] == 0 || haystack.first[j] != needle.first[i])) {
                ++j;
            }
            if (j == static_cast<int>(haystack.first.size())) {
                return false;
            } else {
                const int quantity = min(haystack.second[j], needle.second[i]);
                haystack.second[j] -= quantity;
                needle.second[i] -= quantity;
            }
        }
    }
    return true;
}

int main() {
    ifstream cin("0-caracatita.in");
    ofstream cout("caracatita.out");
    int num_worthy;
    cin >> num_worthy;
    vector<ComprStr> compressed_worthy(num_worthy);
    for (auto& worthy : compressed_worthy) {
        string str;
        cin >> str;
        worthy = compress(str);
    }
    int num_queries;
    cin >> num_queries;
    while (num_queries--) {
        string query;
        cin >> query;
        const ComprStr compressed_query = compress(query);
        const string& str_query = compressed_query.first;
        auto engine = std::default_searcher(str_query.begin(), str_query.end());
        int res = 0;
        for (const auto& compr_worthy : compressed_worthy) {
            const string& str_worthy = compr_worthy.first;
            if (is_subseq(compressed_query, compr_worthy)) {
                auto it = std::search(str_worthy.begin(), str_worthy.end(), engine);
                while (it != str_worthy.end()) {
                    ++res;
                    it = std::search(it + 1, str_worthy.end(), engine);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
