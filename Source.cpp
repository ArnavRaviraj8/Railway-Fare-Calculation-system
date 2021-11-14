#include <iostream>
#include <string> using namespace std; int no;

class railway
// create a class railway

{
	public:

		railway * next;

	string stname;
	//name of the station 
	int ffp;
	//fare from prev

	void allocate(int *f)
	//allocating a particular route in array of link list(recursive function)

	{
		if (*f != 0)

		{
			cout << "\n";

			next = new railway;

			-- *f;

			cout << "\t\tEnter the name of the station : ";

			cin >> stname;

			cin >> ffp;

			cout << "\t\tEnter cost from prev station : ";

			next->allocate(f);

		}
		else

		{
			next = NULL;

		}
	}

	int check(string st)	//Checking whether station exist or not in the route

	{
		if (st == stname)

		{
			return (1);	//found

		}

		if (next == NULL)

			return (-1);	//not found return(next->check(st));
	}

	int faref(string st)	//Calculating the fare

	{
		if (st == stname)

			return (ffp);

		return (next->faref(st) + ffp);	//recursive

	}
};

void sm(railway route, string st, string ed, int *nc)	//smart mapping function (check the start point, end point, clculates fare and displays the route

{
	if (route.check(st) == 1)

	{
		railway *r = &route;

		while (r->stname != st)

		{
			r = r->next;

		}

		if (r->check(ed) == 1)

		{
			*nc = 1;

			cout << "\n\t\tTotal Fare of the route: " << (r->faref(ed) - (r -
				>
				ffp)) << endl;

			cout << "\t\tThe route is  ";

			while (r->stname != ed)

			{
				cout << r->stname << " ---> ";

				r = r->next;

			}

			cout << r->stname << "\n\n";

		}
	}
}

void searchh(railway route[100])	//Taking input of start and end point and calling smart mapping function

{
	string st;

	cout << "\t\tEnter the start point : ";

	cin >> st;

	cout << "\t\tEnter end point :";

	string ed;

	cin >> ed;

	int *nc = new int;

	*nc = 0;

	for (int i = 0; i < no; i++)

		sm(route[i], st, ed, nc);	//smart mapping

	if (*nc == 0)

		cout << "\n\t\tNo routes found \n\n";

}

int main()	//main function

{
	int flag = 0;

	railway route[100];

	string name_route[100];

	no = 0;

	while (flag != 1)

	{
		int n;

		cout << "\n\n\n\t\t\t\t\t\tRailway Reservtion Mapping\n\n";

		cout << "\n\n\t\t1.New Route";
		cout << "\n\t\t2.Search route and get fare";
		cout << "\n\t\t3.Exit";
		cin >> n;

		switch (n)

		{
			case 1:

				{
					no++;
					cout << "\n\n\t\tEnter the number of stations : ";

					int *m = new int;

					cin >> (*m);

					cout << "\t\tEnter the route name : ";
					//identity of each route cin>>name_route[no];
					route[no - 1].allocate(m);
					//allocating routes in array of link list

				}

				break;

			case 2:

				searchh(route);
				//Calls search function

				break;

			case 3:

				break;

				flag = 1;

			default:

				cout << "\t\tWrong Input\n";

				break;

		}
	}

	return 0;

}
