#include <iostream>
#include <vector>

template <class T, int KD_TREE_ORDER = 2> class KdTree {
	enum state {
		KD_TREE_OVERFLOW,
		OK,
	};

	struct node {
		int count;
		int level;
		T data[KD_TREE_ORDER]; //data in the coordenate
		T values[KD_TREE_ORDER]; //values in the node
		node *children[KD_TREE_ORDER + 1];

		node() {
			count = 0;
			
			for (int i = 0; i < KD_TREE_ORDER + 1; ++i) {
				children[i] = NULL;
			}
		}

		void insert_in_node(int pos, const T &value) {
			int j = count;

			while (j > pos) {
				values[j] = values[j - 1];
				children[j + 1] = children[j]
				j --;
			}

			values[j] = value;
			children[j + 1] = children[j];

			count ++;
		}

		bool is_overflow() { return count > KD_TREE_ORDER; }
	};

	node *root;

	public:

	KdTree() { root = new node; level = 0; }

	bool insert(const T &coord[]) {
		if 	
	}

  int insert(node *ptr, const T &value[]) {
    int pos = 0;
    
		while (pos < ptr->count && ptr->values[pos] < value) {
      pos ++;
    }
    
		if (ptr->children[pos] != NULL) {
      int state = insert(ptr->children[pos], value);
      
			if (state == BT_OVERFLOW) {
        split(ptr, pos);
      }
    } 
		
		else {
      ptr->insert_in_node(pos, value);
    }
    
		return ptr->is_overflow() == true ? BT_OVERFLOW : NORMAL;
  }
}
