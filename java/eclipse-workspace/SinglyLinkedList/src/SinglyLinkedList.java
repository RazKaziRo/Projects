
public class SinglyLinkedList {
	
	private Node headNode;
	
	SinglyLinkedList(){
		this.headNode = new Node(null, null);
	}
	
	public int size() {
		
		int counter = 0;
		Node nodeHolder = null;
		
		if(!isEmpty()) {
			
			nodeHolder = headNode.getNextNode();
			
			while(nodeHolder != null) {
				++counter;
				nodeHolder = nodeHolder.nextNode;
			}
		}
		
		return counter;
	}
	
	public Object popFront(){
		
		Node nodeHolder = null;
		
		if(!isEmpty()) {
			
			nodeHolder = headNode.nextNode;
			headNode.nextNode = nodeHolder.nextNode;
		}
		
		return nodeHolder.getData();
	
	}
	
	public void pushFront(Object data) {
		
		Node nodeHolder = headNode.nextNode;
		Node newNode = new Node(data, headNode);
		headNode.nextNode = newNode;
		newNode.nextNode = nodeHolder;
	}
	
	public boolean isEmpty() {
		
		return (this.headNode.nextNode == null);
	}
	
	public ListIterator begin() {
		
		ListIterator itr = new ListIteratorIMP();
		
		return itr;
	}
	
	private class Node{
		
		private Object data;
		private Node nextNode;
		
		Node(Object data, Node nextNode){
			
			this.data = data;
			this.nextNode = nextNode;
		}

		public Object getData() {
			return this.data;
		}

		public Node getNextNode() {
			return this.nextNode;
		}
		
	}
	
	private class ListIteratorIMP implements ListIterator {

		private Node nodeHolder;
		private Object dataHolder = null;
		
		ListIteratorIMP(){
			
			this.nodeHolder = headNode;
		}
		
		@Override
		public boolean hasNext() {
			
			return nodeHolder.getNextNode() != null;
		}

		@Override
		public Object next() {
			
			if(hasNext()) {
				
				dataHolder = nodeHolder.getData();
				nodeHolder = nodeHolder.getNextNode();
			}
			
			return dataHolder;
		}
	}
	
	public static void main(String[] args) {
		
		SinglyLinkedList sll1 = new SinglyLinkedList();
		ListIterator itr = sll1.begin();
		
		System.out.println("SIZE 0: " + sll1.size());

		System.out.println("HAS NEXT FALSE: " + itr.hasNext());

		sll1.pushFront(10);
		
		System.out.println("HAS NEXT TRUE: " + itr.hasNext());

		System.out.println("SIZE 1: " + sll1.size());

		sll1.pushFront(20);
		sll1.pushFront(30);
		sll1.pushFront(40);
		sll1.pushFront(50);

		
		System.out.println("SIZE 5: " + sll1.size());
		
		System.out.println("POP FRONT (50): " + sll1.popFront());
		System.out.println("POP FRONT (40): " + sll1.popFront());
		
		System.out.println("SIZE 3 AFTER 2 POP: " + sll1.size());
		System.out.println(itr.hasNext());
		

	}

}
