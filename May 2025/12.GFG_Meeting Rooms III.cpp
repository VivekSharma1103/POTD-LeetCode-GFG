class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available room numbers
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        // Min-heap for occupied rooms: pair of (endTime, roomNumber)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupiedRooms;

        // To count meetings hosted by each room
        vector<int> meetingCount(n, 0);

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            // Free up rooms that are done before the current meeting's start
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                int freeRoom = occupiedRooms.top().second;
                occupiedRooms.pop();
                availableRooms.push(freeRoom);
            }

            if (!availableRooms.empty()) {
                // Assign meeting to the smallest available room
                int room = availableRooms.top();
                availableRooms.pop();
                long long endTime = (long long)end;
                occupiedRooms.push(make_pair(endTime, room));
                meetingCount[room]++;
            } else {
                // Delay the meeting until the earliest room is free
                long long nextFreeTime = occupiedRooms.top().first;
                int room = occupiedRooms.top().second;
                occupiedRooms.pop();
                long long duration = (long long)(end - start);
                long long newEndTime = nextFreeTime + duration;
                occupiedRooms.push(make_pair(newEndTime, room));
                meetingCount[room]++;
            }
        }

        // Find the room with the most meetings
        int maxMeetings = 0;
        int resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
