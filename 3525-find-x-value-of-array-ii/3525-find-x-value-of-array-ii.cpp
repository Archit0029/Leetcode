class Solution {
    struct Node {
        int cnt[5] = {};
        int prod = 1;
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes ending inside the left part
        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes that contain the whole left part
        // and some prefix of the right part
        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int p, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;
            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;
            return;
        }

        int m = (l + r) >> 1;

        build(p << 1, l, m, nums);
        build(p << 1 | 1, m + 1, r, nums);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            int rem = val % k;

            tree[p] = Node();
            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;

            return;
        }

        int m = (l + r) >> 1;

        if (idx <= m)
            update(p << 1, l, m, idx, val);
        else
            update(p << 1 | 1, m + 1, r, idx, val);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[p];

        int m = (l + r) >> 1;

        if (qr <= m)
            return query(p << 1, l, m, ql, qr);

        if (ql > m)
            return query(p << 1 | 1, m + 1, r, ql, qr);

        Node left = query(p << 1, l, m, ql, qr);
        Node right = query(p << 1 | 1, m + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = K;

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Prefix-product frequencies for nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};