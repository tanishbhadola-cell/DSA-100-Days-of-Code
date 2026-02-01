/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/

#include <stdio.h>
int main() {
        int n , pos,x;
        int arr[100];

        printf("enter the number of elements: ");
        scanf("%d", &n);

         printf("enter %d elements:\n",n);
        for (int i = 0;i < n ;i++)
        {
            scanf("%d",&arr[i]);
        
        }

        printf("enter the position to be inserted:");
        scanf("%d",&pos);

        printf("enter the element to be inserted:");
        scanf("%d",&x);

        if (pos < 1 || pos > n+1)
        {
            printf("invalid position , insertion not possible.\n");
            return 0;
        }
        //we have to shift elements to right inorder to make space
        for(int i = n -1 ; i>=pos - 1; i--)
        {
            arr[i +1 ] = arr[i];
        }
    
        
        arr[pos - 1] = x ;

        printf("the updated array is :\n");

        for (int i=0;i<=n;i++)
        {
            printf("%d",arr[i]);
        }
        return 0 ;

    }
    
       







