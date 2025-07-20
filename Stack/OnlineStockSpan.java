class StockSpanner {

    Stack<List<Integer>> st;
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        int span = 1;
        while(!st.isEmpty() && st.peek().getFirst() <= price) {
            span += st.pop().get(1); 
        }
        st.push(List.of(price, span));
        return span;
    }
}