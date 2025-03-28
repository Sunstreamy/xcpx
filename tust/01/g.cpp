#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128_t i128;
#define N 200005

vector<string> rotate_90(const vector<string>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return {};
    int cols = matrix[0].size();
    vector<string> rotated(cols, string(rows, ' '));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][rows - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

vector<string> rotate_180(const vector<string>& matrix) {
    return rotate_90(rotate_90(matrix));
}

vector<string> rotate_270(const vector<string>& matrix) {
    return rotate_90(rotate_90(rotate_90(matrix)));
}
//p对于每个块，预先计算四个键值，并存储。然后，对于每对块，检查它们的键值集合是否有交集。
string get_key(const vector<string>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return "";
    int cols = matrix[0].size();
    string key = to_string(rows) + "," + to_string(cols) + ",";
    for (const string& row : matrix) {
        key += row;
    }
    return key;
}
//获取所有旋转不同分割大小子块的带行，列的拼图块
vector<string> get_rotation_keys(const vector<string>& block) {
    vector<string> keys;
    vector<string> m = block;
    keys.push_back(get_key(m));
    m = rotate_90(m);
    keys.push_back(get_key(m));
    m = rotate_180(block);
    keys.push_back(get_key(m));
    m = rotate_270(block);
    keys.push_back(get_key(m));
    return keys;
}
//分离出所有符合x行，y列的子块部分
vector<vector<string>> split_blocks(int X, int Y, const vector<string>& grid) {
    int A = grid.size();
    int B = grid[0].size();
    int m = A / X;
    int n = B / Y;
    vector<vector<string>> blocks;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<string> block;
            for (int x = i * X; x < (i + 1) * X; ++x) {
                block.push_back(grid[x].substr(j * Y, Y));
            }
            blocks.push_back(block);
        }
    }
    return blocks;
}
//hash集合加速查找每种分割大小相同的方式旋转不同角度后是否存在相同碎片
bool is_valid(int X, int Y, const vector<string>& grid) {
    auto blocks = split_blocks(X, Y, grid);
    int cnt = blocks.size();
    if (cnt == 1) return true;
    for (int i = 0; i < cnt; ++i) {
        auto keys_i = get_rotation_keys(blocks[i]);
        for (int j = i + 1; j < cnt; ++j) {
            auto keys_j = get_rotation_keys(blocks[j]);
            unordered_set<string> set_j(keys_j.begin(), keys_j.end());
            for (const auto& key : keys_i) {
                if (set_j.count(key)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<pair<int, int>> find_valid_pairs(const vector<string>& grid) {
    int A = grid.size();
    int B = grid[0].size();
    vector<pair<int, int>> valid_pairs;
    for (int X = 1; X <= A; ++X) {
        if (A % X != 0) continue;
        for (int Y = 1; Y <= B; ++Y) {
            if (B % Y != 0) continue;
            if (is_valid(X, Y, grid)) {
                valid_pairs.emplace_back(X, Y);
            }
        }
    }
    return valid_pairs;
}

pair<int, int> find_min_pair(const vector<pair<int, int>>& pairs) {
    pair<int, int> min_pair = pairs[0];
    int min_area = min_pair.first * min_pair.second;
    for (const auto& p : pairs) {
        int area = p.first * p.second;
        if (area < min_area || (area == min_area && p.first < min_pair.first)) {
            min_pair = p;
            min_area = area;
        }
    }
    return min_pair;
}

int main() {
    int A, B;
    cin >> A >> B;
    vector<string> grid(A);
    for (int i = 0; i < A; ++i) {
        cin >> grid[i];
    }
    auto valid_pairs= find_valid_pairs(grid);
    cout << valid_pairs.size() << endl;
    auto mn= find_min_pair(valid_pairs);
    cout << mn.first<< " " << mn.second << endl;
    return 0;
}