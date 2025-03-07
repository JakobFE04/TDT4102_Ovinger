#include "Meeting.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>


// BEGIN 3b
std::ostream& operator<<(std::ostream& os, const Campus& C){
    std::cout << campusToString.at(C) << std::endl;
    return os;
}
// END 3b

// BEGIN 3e
void Meeting::addParticipant(std::shared_ptr<Person> P){
    participants.push_back(P);
}
// END 3e

// BEGIN 3f
Meeting::Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, const std::shared_ptr<Person> leader) : day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, leader{leader}{
    this->addParticipant(leader);
}
// END 3f

// BEGIN 3h
std::vector<std::string> Meeting::getParticipantList() const{
    std::vector<std::string> list;
    for (auto & participant : participants) {
        list.push_back(participant->getName());
    }
    return list;
}
// END 3h

// BEGIN 3i
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting& meeting) const{
    std::vector<std::shared_ptr<Person>> people_list;
    if (meeting.getLocation() == this->getLocation() && meeting.getDay() == this->getDay() && -1 <= meeting.getStartTime()-this->getStartTime() && meeting.getStartTime()-this->getStartTime()<= 1 && -1 <= meeting.getEndTime()-this->getEndTime() && meeting.getEndTime()-this->getEndTime()<= 1){
        for (auto & meetingMember : meeting.participants){
            if (meetingMember->hasAvailableSeats()){
                people_list.push_back(meetingMember);
            }
        }
    }
    return people_list;
}
// END 3i

// BEGIN 3j
std::ostream& operator<<(std::ostream& os, const Meeting& M){
    std::cout << "Subject:" << M.getSubject() << std::endl;
    std::cout << "Location:" << M.getLocation() << std::endl;
    std::cout << "Start time:" << M.getStartTime() << std::endl;
    std::cout << "End time:" << M.getEndTime() << std::endl;
    std::cout << "Leader:" << *M.getLeader() << std::endl;
    std::cout << "Participants: [";
    for (auto& participant : M.getParticipantList()){
        std::cout << participant << ",";
    }
    std::cout << "]" << std::endl;
    return os;
}
// END 3j
