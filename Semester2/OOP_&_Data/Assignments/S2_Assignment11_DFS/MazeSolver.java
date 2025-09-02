import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class MazeSolver {
	private Stack<Node> stack;
	private char[][] maze;
	private int eggFound;
	private int mHeight;
	private int mWidth;
	private Node start;
	
	public MazeSolver() {
		eggFound = 0;
		stack = new Stack<Node>();
		start = new Node(0,0);
		stack.push(start);
	}
	
	public void depthFirstSearch() {
		Node temp;
		try {
			while(stack.isEmpty() == false) {	
				temp = stack.pop();
				/*if(maze[stack.get(x).getX()][stack.get(y).gety()] == 'E'||maze[stack.get(x).getX()][stack.get(y).gety()] == 'e') {
					eggFound++;
				}*/
				if(maze[temp.getX()][temp.gety()] == 'e'||maze[temp.getX()][temp.gety()] == 'E') {
					eggFound++;
				}
				maze[temp.getX()][temp.gety()] = 'x';
				 
				if(temp.getX()+1>=0&&temp.getX()+1<mHeight&&maze[temp.getX()+1][temp.gety()] != '#'&&maze[temp.getX()+1][temp.gety()] != 'x') {
					stack.push(new Node(temp.getX()+1,temp.gety()));
				}
				
					if(temp.gety()+1>=0&&temp.gety()+1<mWidth&&maze[temp.getX()][temp.gety()+1] != '#'&&maze[temp.getX()][temp.gety()+1] != 'x') {
							stack.push(new Node(temp.getX(),temp.gety()+1));
					}
				
					if(temp.getX()-1>=0&&temp.getX()-1<mHeight&&maze[temp.getX()-1][temp.gety()] != '#'&&maze[temp.getX()-1][temp.gety()] != 'x') {
							stack.push(new Node(temp.getX()-1,temp.gety()));
					}
				
					if(temp.gety()-1>=0&&temp.gety()-1<mWidth&&maze[temp.getX()][temp.gety()-1] != '#'&&maze[temp.getX()][temp.gety()-1] != 'x') {
							stack.push(new Node(temp.getX(),temp.gety()-1));
					}
			}
		}catch(Exception e) {
			System.out.print("k");
		}
        /*Mark the current node as visited

        Calculate the coordinate of the adjacent node to the south
        Check if the node coordinates are in bounds of the maze (no negative numbers, etc)
                    Check if the adjacent node is not yet visited and it is not a wall
                                Create a new node from that coordinate and push it into the stack

        Calculate the coordinate of the node to the east
        Check if the node coordinates are in bounds of the maze (no negative numbers, etc)
                    Check if the adjacent node is not yet visited and it is not a wall
                                Create a new node from that coordinate and push it into the stack

        Calculate the coordinate of the node to the north
        Check if the node coordinates are in bounds of the maze (no negative numbers, etc)
                    Check if the adjacent node is not yet visited and it is not a wall
                                Create a new node from that coordinate and push it into the stack

        Calculate the coordinate of the node to the west
        Check if the coordinate is in the bound of the maze (no negative numbers, etc)
                    Check if the adjacent node is not yet visited and it is not a wall
                                Create a new node from that coordinate and push it into the stack*/
	}
	
	public int getEggFound(){
		return eggFound;
	}
	
	public void printMaze() {
		try {
			//System.out.print("\n");
			for (int i = 0; i <= mHeight; i++) {
				for (int j = 0; j < mWidth; j++) {
					System.out.print(maze[i][j]);
				}
				System.out.print("\n");
			}
			System.out.print("\n");
		}catch(Exception e) {
			//System.out.print("j");
		}
	}

	// ************************************************************************************
	// ************** Utility method to read maze from user input *************************
	// ************************************************************************************
	public void readMaze() {

		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Height of the maze: ");
			String line = reader.readLine();
			mHeight = Integer.parseInt(line);

			System.out.println("Width of the maze: ");
			line = reader.readLine();
			mWidth = Integer.parseInt(line);
			maze = new char[mHeight][mWidth];

			for (int i = 0; i < mHeight; i++) {
				line = reader.readLine();
				for (int j = 0; j < mWidth; j++) {
					maze[i][j] = line.charAt(j);
				}
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
