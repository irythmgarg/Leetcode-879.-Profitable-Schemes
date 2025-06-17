# Leetcode-879.-Profitable-Schemes
# 📘 Profitable Schemes - Problem Overview & Approaches

## 💼 Problem Statement

You are given:

* `n` - Maximum number of people available.
* `minProfit` - Minimum profit required.
* `group` - An array where `group[i]` is the number of people required for the i-th job.
* `profit` - An array where `profit[i]` is the profit for the i-th job.

Return the number of different schemes to choose from such that:

* The total number of people used is at most `n`.
* The total profit is at least `minProfit`.

Since the answer can be large, return it modulo **1e9+7**.

---

## ✅ Approach 1: Recursion (Brute Force)

### 🔄 Logic

* Use recursion to explore all subsets of jobs.
* For each job, we either:

  * **Take** the job (if enough people are available).
  * **Skip** the job.
* Base case:

  * If all jobs are considered (`i >= group.size()`), check if `profittillnow >= minProfit`.

### 🔢 Code Structure (Simplified)

```cpp
if (i >= group.size()) {
  return profittillnow >= minProfit ? 1 : 0;
}
if (group[i] <= n) {
  TAKE = hlo(n - group[i], minProfit, ...);
}
nottake = hlo(n, minProfit, ...);
return TAKE + nottake;
```

### ⏱️ Time Complexity

* **Exponential**: `O(2^n)`

### 📦 Space Complexity

* **O(n)** (Recursive call stack)

### ⚠️ Limitations

* TLE (Time Limit Exceeded) for larger inputs due to redundant subproblems.

---

## 🚀 Approach 2: Recursion + Memoization (Top-Down DP)

### 🔄 Logic

* Extend the recursive approach.
* Memoize results in a 3D DP table: `dp[n][profit][i]` to avoid recomputation.
* Use `min(minProfit, profittillnow + profit[i])` to bound state space.

### ✅ Optimized Code Highlights

```cpp
if (dp[n][profittillnow][i] != -1) return dp[n][profittillnow][i];
```

### ⏱️ Time Complexity

* **O(n \* minProfit \* m)**, where `m = group.size()`

### 📦 Space Complexity

* **O(n \* minProfit \* m)** for the DP table

### ✅ Advantages

* Handles large inputs efficiently
* Avoids recomputation of overlapping subproblems

---

## 📊 Example

**Input:**

```cpp
n = 5
minProfit = 3
group = [2,2]
profit = [2,3]
```

**Output:** `2`

**Explanation:**

* Scheme 1: Take job 0 and 1 → total people = 4, profit = 5
* Scheme 2: Take only job 1 → total people = 2, profit = 3

---

## 🧑‍💻 Author

**Ridham Garg**
B.Tech Computer Engineering
Thapar University, Patiala
Roll No: 102203014

---

## 🔚 Conclusion

* For small inputs, recursion works fine.
* For large constraints, memoization is **essential** to avoid TLE.
* The use of `min(minProfit, currentProfit)` is a clever trick to reduce state space.

✨ Both approaches help in understanding how to transition from brute-force to optimized dynamic programming solutions!
