#include "Podcast.h"

const vector<string> Podcast::ALL_TOPICS{ "Aliens", "Tambal", "Contrabas", "Acordeon", "Cobza", "Global warming",
	"Stand-up", "Dad jokes", "Video games", "Cancel culture", "Manele", "Youtube algorithm",
	"Feminism", "Neo-nazism", "Books"};
const vector<string> Podcast::GUESTS{ "Bill Burr", "Dan Avidan", "Pewdiepie", "Codin Pop",
                                     "Ramona Cordos", "Cazaciuc Valentin", "Matei Anechitei",
                                     "Jimmy Carr", "Teo", "Vio", "Costel", "Micutzu"};

Podcast::Podcast(): AudioRecording("", 0, 0) {
	host = "";
	guest = "";
	topics = {};
}

Podcast::Podcast(int length, string host, string guest, vector<string> topics): AudioRecording("", length) {
	this->host = host;
	this->guest = guest;
	this->topics = topics;
}

Podcast::Podcast(string name, int length, double views, string host, string guest, vector<string> topics):
    AudioRecording(name, length, views) {
    this->host = host;
    this->guest = guest;
    this->topics = topics;
}

Podcast::Podcast(int length, string host, string guest): AudioRecording("", length) {
	this->host = host;
	this->guest = guest;
	this->topics = {};
}

Podcast::Podcast(const Podcast& podcast): AudioRecording(podcast) {
	this->host = podcast.host;
	this->guest = podcast.guest;
	this->topics = podcast.topics;
}

Podcast::~Podcast() {};

Podcast& Podcast::operator =(const Podcast& podcast) {
    if(this == &podcast) {
        return *this;
    }

    AudioRecording::operator=(podcast);

	this->host = podcast.host;
	this->guest = podcast.guest;
	this->topics = podcast.topics;

	return *this;
}

ostream& Podcast::virtualPrint(ostream& out) const{
    AudioRecording::virtualPrint(out);
	out << "\nHost: " << host;
	out << "\nGuest: " << guest;
	out << "\nTopics: ";

	for (auto topic : topics) {
		out << topic << ", ";
	}

	return out;
}

istream& Podcast::virtualRead(istream& in) {
    AudioRecording::virtualRead(in);

	cout << "\nHost: ";
	in >> host;

	cout << "\nGuest: ";
	in >> guest;

	cout << "\nHow many topics have been discussed: ";
	int topicNum;
	in >> topicNum;
	
	string topic;
	cout << "\nTopics: ";
	for (int i = 0; i < topicNum; i++) {
		in >> topic;
		topics.push_back(topic);
	}

	return in;
}

string& Podcast::operator[](int index) {
	if (index > topics.size()) {
		cout << "Invalid index";
		exit(0);
	}

	return topics[index];
}

/*
 * Operator ++ will add a new topic to the topic list.
 */
Podcast& Podcast::operator++() {
	topics.push_back(RandomHelper::getRandomTopic());

	return *this;
}

Podcast Podcast::operator++(int) {
	Podcast temp(*this);
	topics.push_back(RandomHelper::getRandomTopic());

	return temp;
}


/*
 * Adding 2 podcasts will merge their topic lists.
 */
Podcast Podcast::operator +(const Podcast& podcast) {
	Podcast tempPodcast;

	tempPodcast.topics.insert(tempPodcast.topics.end(), this->topics.begin(), this->topics.end());
	tempPodcast.topics.insert(tempPodcast.topics.end(), podcast.topics.begin(), podcast.topics.end());

	return tempPodcast;
}


/*
 * Subtracting 2 podcasts will remove the common topics.
 */
Podcast Podcast::operator -(const Podcast& podcast) {
	Podcast tempPodcast;

	for (auto topic : this->topics) {
		auto it = find(podcast.topics.begin(), podcast.topics.end(), topic);

		if (it == podcast.topics.end()) {
			tempPodcast.topics.push_back(topic);
		}
	}

	return tempPodcast;
}

bool operator <(const Podcast& podcast1, const Podcast& podcast2) {
	return podcast1.topics.size() < podcast2.topics.size();
}

bool operator ==(const Podcast& podcast1, const Podcast& podcast2) {
	return podcast1.host == podcast2.host
	    && podcast1.guest == podcast2.guest
	    && podcast1.topics == podcast2.topics
	    && podcast1.length == podcast2.length;
}

/*
 * Recording will generate a new podcast with random topics.
 * Each topic takes about 15 mins of time.
 */
Podcast Podcast::recordPodcast(string host, string guest, int length) {
	Podcast newPodcast(length, host, guest);
	int topicCount = length / Podcast::TOPIC_LENGTH;

	for (int i = 0; i < topicCount; i++) {
		string newTopic = RandomHelper::getRandomTopic();
		auto it = find(newPodcast.topics.begin(), newPodcast.topics.end(), newTopic);

		if (it == newPodcast.topics.end()) {
			newPodcast.topics.push_back(newTopic);
		}
	}

	return newPodcast;
}

void Podcast::play() {
    cout << endl;
    for(string topic:topics) {
        cout << topic << " ";
    }
}

