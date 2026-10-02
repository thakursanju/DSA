class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();

        backtrack("", 0, 0, n, result);

        return result;
    }

    void backtrack(String s, int open, int close, int n, List<String> result) {

        if (open == n && close == n) {
            result.add(s);
            return;
        }

        // Add '('
        if (open < n) {
            backtrack(s + "(", open + 1, close, n, result);
        }

        // Add ')'
        if (close < open) {
            backtrack(s + ")", open, close + 1, n, result);
        }
    }
}