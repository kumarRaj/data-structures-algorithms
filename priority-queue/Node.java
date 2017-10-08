class Node{
    Object data;
    int priority;

    public Node(Object d, int p){
        data = d;
        priority = p;
    }

    public String toString(){
        return "" + priority;
    }
}
