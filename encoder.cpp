#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

}

void display()                       // Reset the model-view matrix
{
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();

}

void graph()
{
    glLineWidth(2);
    //print reference lines
    for(int i=0 ; i< 15 ; i++)
    {
     glEnable(GL_LINE_STIPPLE);
     glLineStipple(1,0x0FF);
     glBegin(GL_LINES);
     glColor3f( 1.0f, 1.0f, 1.0f);
     glVertex2f(i*0.05,-0.5);
     glColor3f( 0.0f, 1.0f, 0.0f);
     glVertex2f(i*0.05, 0.5);
     glEnd();
     glFlush();
     glDisable(GL_LINE_STIPPLE);
    }

     glBegin(GL_LINES);
     glColor3f( 0.0f, 0.7f, 0.0f);
     glVertex2f(0,0);                                 //coordinate axis
     glVertex2f(1,0);
     glVertex2f(0,0.5);
     glVertex2f(0,-0.5);

     glEnd();
     glFlush();
}


void NRZ_L(int arr[])
{
    graph() ;
    for(int i=0 ; i< 14 ; i++)
    {
      int flag = 0 , next = 0;

      if(arr[i]==arr[i+1] && i <=12)  flag = 1  ;
      if(arr[i]==arr[i-1] && i >=1 )  next  = 1 ;
  

      if(arr[i]==0)
      {
          glBegin(GL_LINE_STRIP);
          glColor3f( 1.0f, 1.0f, 1.0f);
          if(next != 1)
          glVertex2f(i*0.05,0);
          glVertex2f(i*0.05,-0.2);
          glVertex2f(i*0.05+0.05, -0.2);
          if( flag != 1)
          glVertex2f(i*0.05+0.05 , 0 );
          glEnd();
          glFlush();
       }

      else
      {
          glBegin(GL_LINE_STRIP);
          glColor3f( 1.0f, 1.0f, 1.0f);
          if(next != 1)
          glVertex2f(i*0.05,0);
          glVertex2f(i*0.05,0.2);
          glVertex2f(i*0.05+0.05, 0.2);
          if( flag != 1)
          glVertex2f(i*0.05+0.05 , 0 );
          glEnd();
          glFlush();
       }
    }
}                                                 //END of NRZ-L

void manch(int arr[])
{
    graph() ;

    for(int i=0 ; i< 14 ; i++)
    {
      if(arr[i] == arr[i-1] && i>0)
      {
          glBegin(GL_LINES);
          glColor3f( 1.0f, 1.0f, 1.0f);
          glVertex2f(i*0.05,0.2);
          glVertex2f(i*0.05,-0.2);
          glEnd();
      }

      if(arr[i]==0)
      {
          glBegin(GL_LINE_STRIP);
          glColor3f( 1.0f, 1.0f, 1.0f);
          glVertex2f(i*0.05,0.2);
          glVertex2f(i*0.05+0.025,0.2);
          glVertex2f(i*0.05+0.025, -0.2);
          glVertex2f(i*0.05+0.05 , -0.2 );
          glEnd();
          glFlush();
      }
      else
      {
          glBegin(GL_LINE_STRIP);
          glColor3f( 1.0f, 1.0f, 1.0f);
          glVertex2f(i*0.05,-0.2);
          glVertex2f(i*0.05+0.025,-0.2);
          glVertex2f(i*0.05+0.025, 0.2);
          glVertex2f(i*0.05+0.05 , 0.2 );
          glEnd();
          glFlush();
      }
    }
}                                                 //END of manchester

void print_z(int i)
{
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 1.0f, 1.0f);
        glVertex2f(i*0.05,0.2);
        glVertex2f(i*0.05+0.025,0.2);
        glVertex2f(i*0.05+0.025, -0.2);
        glVertex2f(i*0.05+0.05 , -0.2 );
        glEnd();
        glFlush();
}

void print_s(int i)
{
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 1.0f, 1.0f);
        glVertex2f(i*0.05,-0.2);
        glVertex2f(i*0.05+0.025,-0.2);
        glVertex2f(i*0.05+0.025, 0.2);
        glVertex2f(i*0.05+0.05 , 0.2 );
        glEnd();
        glFlush();

}

void diff_manch(int arr[])
{
    graph() ;
    int last = 0 ;
    for(int i=0 ; i< 14 ; i++)
    {
        if(i == 0 )
        {
          if(arr[i]==0)
           {
           print_z(i) ;
           }
          else
           {
           print_s(i);
           last = 1 ;
           }
        }
        else
        {

            if(last==1  )
            {

               if(arr[i]==0)
               {
                   glBegin(GL_LINES);
                   glColor3f( 1.0f, 1.0f, 1.0f);
                   glVertex2f(i*0.05,0.2);
                   glVertex2f(i*0.05,-0.2);
                   glEnd();
                   print_s(i) ;
                   last = 1;
               }
               else
               {
                   print_z(i) ;
                   last = 0;
               }
            }
            else
            {
              if(arr[i]==1)
              {
                  print_s(i) ;
                  last = 1;
              }
              else
              {
                  glBegin(GL_LINES);
                  glColor3f( 1.0f, 1.0f, 1.0f);
                  glVertex2f(i*0.05,0.2);
                  glVertex2f(i*0.05,-0.2);
                  glEnd();
                  print_z(i) ;
                  last = 0;
              }
            }
        }
    }
}                                                                             //END of differential-manchester

void AMI(int arr[])
{
  graph() ;
  int c=0;
  for(int i=0 ; i< 14 ; i++)
  {

    if(arr[i]==0)
    {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 1.0f, 1.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05+0.05,0);
        glEnd();
        glFlush();
     }
    else
    {
       if(c%2==0)
       {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 1.0f, 1.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05,0.2);
        glVertex2f(i*0.05+0.05, 0.2);
        glVertex2f(i*0.05+0.05 , 0 );
        glEnd();
        glFlush();
       }


       else if(c%2==1)
      {
        glBegin(GL_LINE_STRIP);
        glColor3f( 1.0f, 1.0f, 1.0f);
        glVertex2f(i*0.05,0);
        glVertex2f(i*0.05,-0.2);
        glVertex2f(i*0.05+0.05,-0.2);
        glVertex2f(i*0.05+0.05 , 0 );
        glEnd();
        glFlush();
      }
      c++;
    }
  }
}                                                                           //END of basic AMI

void draw_positive(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 1.0f, 1.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05,0.1);
            glVertex2f(i*0.05+0.05,0.1);
            glVertex2f(i*0.05+0.05,0);
            glEnd();                                                          //used by HDB3 and B8Z5
            glFlush();
}

void draw_negative(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 1.0f, 1.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05,-0.1);
            glVertex2f(i*0.05+0.05,-0.1);
            glVertex2f(i*0.05+0.05,0);
            glEnd();                                                            //used by HDB3 and B8Z5
            glFlush();
}
void draw_zero(int i)
{
            glBegin(GL_LINE_STRIP);
            glColor3f( 1.0f, 1.0f, 1.0f);
            glVertex2f(i*0.05,0);
            glVertex2f(i*0.05+0.05,0);
            glEnd();
            glFlush();
}
void hdb3(int arr[])
{
   graph();
   int i=0;
   int count_one=1;
   int count_strict=0;
   while(i<14)
   {
      if(arr[i]==1)
      {
         ++count_strict;
         ++count_one;
         if(!(count_one & 1))
            draw_positive(i);
          else
             draw_negative(i);
          ++i;
      }
      else if(arr[i]==0)
      {
          int count_zeroes=0;
          int j=i;
          int t=j+3;
          if(t<=13)
          {
             while(j<=t)
             {
                if(arr[j]==0)
                  ++count_zeroes;
                else
                  break;
                ++j;
             }
          }
             if(count_zeroes==4)
            {
            if(!(count_strict & 1))
            {
              count_one+=1;
              int t=0;
              int p=i;
              while(i<=p+3)
               {
                 if(t==0)
                  {
                    if(!(count_one & 1))
                      draw_positive(i);
                   else
                     draw_negative(i);
                   t=1;
                   ++i;
                  }
              else
              {
                 if(t==3)
                 {
                    if(!(count_one & 1))
                       draw_positive(i);
                   else
                       draw_negative(i);
                ++i;
                ++t;
                }
                else
                {
                   draw_zero(i);
                  ++t;
                  ++i;

                }
          }
              }
              count_strict+=2;
              }
              else if(count_strict & 1)
              {
                 int t=0;
                 int p=i;
                 while(i<=p+3)
                 {
                     if(t==3)
                     {
                       if((count_one & 1))
                 {
                   draw_negative(i);
                 }
                   else
                {
                 draw_positive(i);
                }
                ++i;
                ++t;
                     }
                     else
                     {
                        draw_zero(i);
                        ++i;
                        ++t;
                     }
                 }
               count_strict+=1;
              }
             }
             else
             {
                draw_zero(i);
               ++i;
             }
          }
      }
   }                                                                               //end of HDB3


void B8Z5(int arr[])
{
   graph();
   int count_one=1;
   int i=0;
   while(i<14)
   {
      if(arr[i]==1)
      {
         ++count_one;
         if(!(count_one & 1))
            draw_positive(i);
         else
             draw_negative(i);
         ++i;
      }
      else if(arr[i]==0)
      {
       int count_zeroes=0;
          int j=i;
          int t=j+7;
           if(t<=11)
          {
             while(j<=t)
             {
                if(arr[j]==0)
                  ++count_zeroes;
                else
                  break;
                ++j;
             }
          }
           if(count_zeroes==8)
           {
           //here 000v starts
              int t=0;
                 int p=i;
                 while(i<=p+3)
                 {
                     if(t==3)
                     {
                       if((count_one & 1))
                 {
                   draw_negative(i);
                 }
                   else
                {
                 draw_positive(i);
                }
                ++i;
                ++t;
                     }
                     else
                     {
                        draw_zero(i);
                        ++i;
                        ++t;
                     }
                 }
               count_one+=1;
               //now bOVB start here
                        t=0;
               p=i;
               while(i<=p+3)
               {
                 if(t==0)
                  {
                    if(!(count_one & 1))
                      draw_positive(i);
                   else
                     draw_negative(i);
                   t=1;
                   ++i;
                  }
              else
              {
                if(t==2)
                {
                 if(!(count_one & 1))
                       draw_positive(i);
                   else
                       draw_negative(i);
                ++i;
                ++t;


                }
                 if(t==3)
                 {
                    if(!(count_one & 1))
                       draw_negative(i);
                   else
                       draw_positive(i);
                ++i;
                ++t;
                ++count_one;
                }
                else
                {
                   draw_zero(i);
                  ++t;
                  ++i;

                }
          }
              }

           }
           else
           {
             draw_zero(i);
             ++i;

           }
      }
   }
}                                                                                        //end of B8Z5

void NRZ_I(int arr[])
{
     graph() ;
     int flag=0;
     int nnot;
     for(int i=0;i<14;i++)
     {
        glColor3f( 1.0f, 1.0f, 1.0f);
        if(arr[i+1]==0 && i<=12)
          flag=1;
        else
         flag=0;
        if(i==0 )
        {

        if(arr[i]==1)
        {
           glBegin(GL_LINE_STRIP);
           glVertex2f(i*0.05,0);
           glVertex2f(i*0.05,0.2);
           glVertex2f(i*0.05+0.05, 0.2);
           if(flag!=1)
           glVertex2f(i*0.05+0.05 , 0 );
           nnot=1;
           glEnd();
           glFlush();
        }
        else
        {
           glBegin(GL_LINE_STRIP);
           glVertex2f(i*0.05,0);
           glVertex2f(i*0.05,-0.2);
           glVertex2f(i*0.05+0.05, -0.2);
           if(flag!=1)
           glVertex2f(i*0.05+0.05 , 0 );
           nnot=-1;
           glEnd();
           glFlush();
        }
        }
        else
        {
           if(arr[i]==1)
           {
              if(nnot==-1)
              {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,0);
              glVertex2f(i*0.05,0.2);
              glVertex2f(i*0.05+0.05, 0.2);
              if(flag!=1)
              glVertex2f(i*0.05+0.05 , 0 );
              nnot=1;
              glEnd();
              glFlush();
              }
              else
              {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,0);
              glVertex2f(i*0.05,-0.2);
              glVertex2f(i*0.05+0.05, -0.2);
              if(flag!=1)
              glVertex2f(i*0.05+0.05 , 0 );
              nnot=-1;
              glEnd();
              glFlush();
              }
           }
           else
           {
             if(nnot==-1)
             {
              glBegin(GL_LINE_STRIP);
              glVertex2f(i*0.05,-0.2);
              glVertex2f(i*0.05+0.05, -0.2);
              if(flag!=1)
              glVertex2f(i*0.05+0.05 , 0 );
              nnot=-1;
              glEnd();
              glFlush();
             }
             else
             {
               glBegin(GL_LINE_STRIP);
               glVertex2f(i*0.05,0.2);
               glVertex2f(i*0.05+0.05, 0.2);
               if(flag!=1)
               glVertex2f(i*0.05+0.05 , 0 );
               nnot=1;
               glEnd();
               glFlush();
             }
           }
        }
     }
}                                                                                  //end of NRZ-I

void printSubStr(string str, int low, int high)
{
    for( int i = low; i <= high; ++i )
        printf("%c ", str[i]);
}

// function prints the longest palindrome substring
void longestPalSubstr(string str)
{
    int maxLength = 1;  // The result (length of LPS)

    int start = 0;
    int len = str.length();

    int low, high;
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        // Find the longest odd length palindrome with center
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    printf("\n\nLongest palindrome substring is: \n\n");
    cout<<"---------------------------------"<<endl ;
    printSubStr(str, start, start + maxLength - 1);


    cout<<"\n\nLength of longest palindrome: "<<maxLength<<endl ;
}                                                                                       //end of palindrome function

string array_to_string(int arr[] , int size_of_array)
{
  string S = "";
  for(int i =0 ; i< size_of_array ; i++)
  {
    S += to_string(arr[i]) ;
  }
  return S ;
}

void digitalData ()
{
 cout<<"Choose the type of Data generation : "<<endl ;
 cout<<"1.completely random sequence "<<endl ;
 cout<<"2.A random sequence with fixed sub-sequences"<<endl ;
 int data_choice  ;
 cin>>data_choice ;
 int no_of_zeros ;
 srand(time(NULL));
 int input[14] ;
 if(data_choice == 2)
   {
   cout<<"Choose the subsequence : "<<endl;
   cout<<"1. 8 consecutive zeros"<<endl;
   cout<<"2. 4 consecutive zeros"<<endl;
   cin>>no_of_zeros ;

   if(no_of_zeros == 1)  //no_of_zeros = 8
   {
     for(int i =0 ; i< 14 ; i++)
     {
      input[i]= rand() & 1 ;
     }

      int start_index = rand() %  7 ;
      cout<<start_index<<endl;
      for(int i = start_index; i<start_index+8 ; i++)
      {
         input[i] = 0 ;
      }
   }
   else   //no_of_zeros = 4
   {
    for(int i =0 ; i< 14 ; i++)
    {
    input[i]= rand() & 1 ;
    }
      int start_index = rand() %  11 ;
      for(int i = start_index; i<start_index+4 ; i++)
      {
        input[i] = 0 ;
      }


   }
 }

else{
     for(int i =0 ; i< 14 ; i++)
     {
      input[i]= ( rand() & 1) ;
      }
     }
   cout<<"\n14 bit Data stream generated is : \n---------------------------------"<<endl ;
   for(int i =0 ; i<14 ; i++)
   {
    cout<<input[i]<<" ";
   }

   string  s = array_to_string(input,14) ;
   longestPalSubstr(s) ;
   cout<<"---------------------------------"<<endl ;
   cout<<"choose the Encoding scheme: "<<endl ;
   cout<<"\n                              |=====================|";
   cout<<"\n                              ||   1 : NRZ-L       ||";
   cout<<"\n                              ||   2 : NRZ-I       ||";
   cout<<"\n                              ||   3 : MANCHESTER  ||";
   cout<<"\n                              ||   4 : MANCH. DIFF ||";
   cout<<"\n                              ||   5 : AMI         ||";
   cout<<"\n                               `===================='";
   cout<<"\n\n                                   Enter Choice : ";
   int scheme ;
   cin>>scheme ;

   if(scheme==1)
   {
    glutInitWindowSize(840, 480);     // Set the window's initial width & height - non-square
    glutInitWindowPosition(500, 100); // Position the window's initial top-left corner
    glutCreateWindow("NRZ-L");        // Create window with the given title
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
    glLoadIdentity();                 // Reset Projection matrix
    gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
    NRZ_L(input) ;
   }

   else if (scheme==2)
   {

     glutInitWindowSize(840, 480);     // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);    // Position the window's initial top-left corner
    glutCreateWindow("NRZ-I");         // Create window with the given title
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);       // Select the Projection matrix for operation
    glLoadIdentity();                  // Reset Projection matrix
    gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
    NRZ_I(input) ;
   }

   else if(scheme == 3)
   {
    glutInitWindowSize(840, 480);            // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);          // Position the window's initial top-left corner
    glutCreateWindow("Biphase Manchester");  // Create window with the given title
    glutDisplayFunc(display);
     glMatrixMode(GL_PROJECTION);            // Select the Projection matrix for operation
    glLoadIdentity();                        // Reset Projection matrix
    gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
    manch(input) ;
   }

   else if(scheme == 4)
   {
   glutInitWindowSize(840, 480);   // Set the window's initial width & height - non-square
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Differential Manchester ");  // Create window with the given title
   glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
    glLoadIdentity();                 // Reset Projection matrix
    gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
   diff_manch(input) ;
   }

   else{

   cout<<"Do you want to use scrambling techniques : "<<endl;
   cout<<"1. Yes"<<endl;
   cout<<"2. No "<<endl;
   int decision ;
   cin>>decision ;

     if(decision == 1)
     {
     cout<<"Choose scrambling techniques : "<<endl;
     cout<<"1. B8Z5"<<endl;
     cout<<"2. HDB3"<<endl;
     int tech ;
     cin>>tech ;

     if(tech == 2)
     {
       glutInitWindowSize(840, 480);     // Set the window's initial width & height - non-square
       glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
       glutCreateWindow("HDB3");         // Create window with the given title
       glutDisplayFunc(display);
       glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
       glLoadIdentity();                 // Reset Projection matrix
       gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
       hdb3(input) ;
     }
     else{
       glutInitWindowSize(840, 480);   // Set the window's initial width & height - non-square
       glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
       glutCreateWindow("B8Z5");  // Create window with the given title
       glutDisplayFunc(display);
       glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
       glLoadIdentity();                 // Reset Projection matrix
       gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
       B8Z5(input) ;
     }
     }
     else{
       glutInitWindowSize(840, 480);   // Set the window's initial width & height - non-square
       glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
       glutCreateWindow("Differential Manchester ");  // Create window with the given title
       glutDisplayFunc(display);
       glMatrixMode(GL_PROJECTION);      // Select the Projection matrix for operation
       glLoadIdentity();                 // Reset Projection matrix
       gluOrtho2D(-0.05, 0.75, -0.5, 0.5);
       AMI(input) ;
     }

   }

}

void prog()
{
    digitalData() ;
    initGL() ;
    glutMainLoop() ;
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    prog();
    return 0;
}
