static Node midNode(Node root){
      if(root==null || root.right==null){
          return root;
      }
      Node slow = root, fast = root;
      while(fast.right!=null && fast.right.right!=null){
          slow = slow.right;
          fast = fast.right.right;
      }
      return slow;
  }

  // left : prev, right : next
  public static Node SortedDLLToBST(Node head) {
    if(head==null || head.right==null){
        return head;
    }
    Node midNode = midNode(head);
    Node prev = midNode.left, next = midNode.right;
    midNode.right = midNode.left = next.left = null;
    if(prev!=null){
        prev.right = null;
    }
    midNode.left = SortedDLLToBST(prev==null ? null : head);
    midNode.right = SortedDLLToBST(next);
    return midNode;
  }