//cs20b1067
//kodam karthik
//menu driven code for finding area and volume of various shapes using classes.

#include <iostream>
using namespace std; //using namespace

class area //class area for finding area of all shapes
{
private:
    int length; //different dimensions declared in private
    int breadth;
    int radius;

public:
    friend class volume;

    inline area() //constructor
    {
        length = 1;
        breadth = 1;
        radius = 1;
    }

    inline void cData() //member function for getting values of dimension
    {
        cout << "enter the length of rectangle" << endl;
        cin >> length;
        cout << "enter the breadth of rectangle" << endl;
        cin >> breadth;
    }
    inline void cirData() //member function for getting radius of circle
    {
        cout << "enter the radius of Circle" << endl;
        cin >> radius;
    }

    friend inline int rectangle(area a1);
    friend inline float Circle(area a2);
};
inline int rectangle(area a1) //member function for finding rectangular area
{
    return a1.length * a1.breadth;
}
inline float Circle(area a2) //member function for finding area of circle
{
    return double(22 * a2.radius * a2.radius) / 7.0;
}

class volume //class volume is declared
{
private: //all dimensions are under private
    int length;
    int breadth;
    int height;
    int radius;

public:
    //using friend function for accessing area class parameters
    volume() //constructor
    {
        length = 1;
        breadth = 1;
        height = 1;
        radius = 1;
    }
    inline void crData() //member function for getting dimensions from user
    {
        cout << "enter the length of Cuboid" << endl;
        cin >> length;
        cout << "enter the breadth of Cuboid" << endl;
        cin >> breadth;
        cout << "enter the height of Cuboid" << endl;
        cin >> height;
    }
     void createData() //member function for getting dimensions from user
    {
        cout << "enter the radius of Circle" << endl;
        cin >> radius;
    }
    
    
    friend inline float volumeSphere(volume v1);
    friend inline int volumeCuboid(volume v2);

};
inline int volumeCuboid(volume v1) //friend function for volume of cuboid
    {
        return v1.length * v1.breadth * v1.height;
    }
 inline   float volumeSphere(volume v2) //friend function for volume of sphere
    {
        return double(88 * v2.radius * v2.radius * v2.radius) / 21;
    }

int  main()
{
    int choice;
    area a1, a2;   //two objects under area class are declared
    volume v1, v2,v3; //two objects under volume class are declared
    cout << "---------MENU FOR VARIOUS OPERATIONS-----------" << endl;
    cout << "1).Area of rectangle \n2).Area of Circle \n3).Unit Area of rectangle \n4).Unit Area of Circle \n";
    cout << "5).Unit volume of Cuboid \n6).Unit volume of Sphere \n7).volume of Cuboid \n";
    cout << "8).volume of Sphere \n9).compare volume of Cuboids \n10).compare volume of Spheres \n\n\n";

    while (true) //menu for all possible cases using switch.
    {
        cout << "Enter your choice from menu" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            a1.cData();
            cout << "The area of rectangle is : " << rectangle(a1) << endl;
            break;
        }
        case 2:
        {
            a1.cirData();
            cout << "The Area of Circle is : " << Circle(a1) << endl;
            break;
        }   
        case 3:
        {
            cout << "Unit Area of rectangle is :" <<rectangle(a1) << endl;
            break;
        }   
        case 4:
        {
            cout << "Unit Area of Circle is :" << Circle(a1) << endl;
            break;
        }   
        case 5:
        {
            cout << "Unit Volume of Cuboid is :" << volumeCuboid( v3) << endl;
            break;
        }   
        case 6:
        {
            cout << "Unit Volume of Sphere is :" << volumeSphere(v3) << endl;
            break;
        }   
        case 7:
        {
            v1.crData();
            cout << "Volume of Cuboid is :" << volumeCuboid(v1) << endl;
            break;
        }   
        case 8:
        {
            v1.createData();
            cout << "Volume of Sphere is :" << volumeSphere(v1) << endl;
            break;
        }   
        case 9:
        {
            cout << "Enter the parameters of 1st Cuboid." << endl;
            v1.crData();
            cout << "Enter the parameters of 2nd Cuboid" << endl;
            v2.crData();
            
            
            if (volumeCuboid(v1)==volumeCuboid(v2))
                cout << "Both Spheres are equal in Volume" << endl;
            if (volumeCuboid(v1) > volumeCuboid(v2))
                cout << "Volume of Cuboid 1 is larger" << endl;
            if (volumeCuboid(v1) < volumeCuboid(v2))
                cout << "volume of Cuboid 2 is larger" << endl;
            break;
        }   
        case 10:
        {
            cout << "Enter the parameters of 1st Sphere." << endl;
            v1.createData();
            cout << "Enter the parameters of 2nd Sphere" << endl;
            v2.createData();
            if (volumeSphere(v1) == volumeSphere(v2))
                cout << "Both Spheres are equal in Volume" << endl;
            if (volumeSphere(v1) > volumeSphere(v2))
                cout << "volume of Sphere 1 is larger" << endl;
            if (volumeSphere(v1) < volumeSphere(v2))
                cout << "volume of Sphere 2 is larger" << endl;
            break;
        }   
        case 11:
        {
            exit(0);
            break;
        }    
        default:
        {
            cout << "Enter correct choice from menu! \n ";
            break;
        }
    }
    }
    return 0;
}