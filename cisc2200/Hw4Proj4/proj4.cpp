#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;

struct Event {
	int time;
	int length;
	Event(int t, int l);	
};

struct EventList {
	priority_queue<Event> events;
	int count;
	void fill(istream& is);
	void simulate();
};

int main(int argc, char** argv) {
	EventList eventList;

	char* progname = argv[0];
	switch (argc) {
		case 1:
			eventList.fill(cin);
			break;
		case 2: {
			ifstream ifs(argv[1]);
			if (!ifs) {
				cerr << progname << ": couldn't open " << argv[1] << endl;
				return 1;
			}
			eventList.fill(ifs);
			break;
		}
		default:
			cerr << "Usage: " << progname << " [datafile]\n";
			return 2;
	}
	eventList.simulate();
}

Event::Event(int t, int l) {
	time = t;
	length = l;
}

void EventList::fill(istream& is) {
	int arrival = 0;
	int time = 0;
	int recent = 0;
	Event e(arrival, time);
	count = 0;
	while (is >> arrival >> time) {
		count++;
		recent = e.time;
		e.time = arrival;
		e.length = time;
		if (recent > e.time) {
			cerr << "Customer #" << count << " out of order (time = " 
				<< e.time << ", previous time = " << recent << ")\n";
			throw 3;
		}
		events.push(e);
	}
}

void EventList::simulate() {
	int time = 0;
	int wait = 0;
	while (!events.empty()) {
		Event e = events.top();
		events.pop();
		if (e.length >= 0) {
			time = max(e.time, time);
			wait += time - e.time;
			time += e.length;
			Event depart(time, -1);
			events.push(depart);
			cout << "Processing an arrival event at time:" << setw(5) << e.time << endl;
		}
		else
			cout << "Processing a departure event at time:" << setw(4) << e.time << endl;
	}
	cout << endl << "Final statistics:\n";
	cout << setw(41) << "Total number of people processed:     ";
	cout << count << endl;
	cout << setw(41) << "Average amount of time spent waiting: "
		<< (double) wait / count << endl;
}

bool operator<(const Event &first, const Event &second) {
	return second.time < first.time;
}
