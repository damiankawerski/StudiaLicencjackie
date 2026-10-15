use std::cmp::Ordering;

#[derive(PartialEq, Eq, Debug)]
struct Time {
    hour: u8,
    minute: u8,
    second: u8,
}


impl Time {
    fn to_string(&self) -> String {
        format!("{}:{}:{}", self.hour, self.minute, self.second)
    }

    fn from_3(hour: u8, minute: u8, second: u8) -> Self {
        Self { hour, minute, second }
    }

    fn from_string(string: &str, delim: char) -> Self {
        let parts: Vec<&str> = string.split(delim).collect();

        let hour:u8 = parts[0].trim().parse().unwrap();
        let minute:u8 = parts[1].trim().parse().unwrap();
        let second:u8 = parts[2].trim().parse().unwrap();

        Self { hour, minute, second }
    }
}

impl PartialOrd for Time {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Time {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.hour != other.hour {
            return self.hour.cmp(&other.hour)
        }

        if self.minute != other.minute {
            return self.minute.cmp(&other.minute);
        }

        self.second.cmp(&other.second)
    }
}


#[derive(Debug, PartialEq, PartialOrd, Ord, Eq)]
enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
}

impl Month {
    fn to_string(&self) -> &'static str {
        match self {
            Month::January => "January",
            Month::February => "February",
            Month::March => "March",
            Month::April => "April",
            Month::May => "May",
            Month::June => "June",
            Month::July => "July",
            Month::August => "August",
            Month::September => "September",
            Month::October => "October",
            Month::November => "November",
            Month::December => "December",
        }
    }
}

#[derive(Debug, Eq)]
struct Date {
    year: u16,
    month: Month,
    day: u8,
    time: Option<Time>
}

impl Date {
    fn to_string(&self) -> String {
        match &self.time {
            Some(t) => format!("{} - {} - {} ; {}", self.day, self.month.to_string(), self.year, t.to_string()),
            None => format!("{} - {} - {}", self.day, self.month.to_string(), self.year),
        }
    }

    fn from_3(day: u8, month: Month, year: u16) -> Self {
        Self { day, month, year, time: None }
    }

    fn from_string(string: &str, delim: char) -> Self {
        let parts:Vec<&str> = string.split(delim).collect();

        if parts.len() != 3 {
            panic!("Expected 3 parts in date string, got {}", parts.len());
        }

        let day: u8 = parts[0].trim().parse().unwrap_or(0);

        let month_str = parts[1].trim();

                let month = match month_str {
            "January" => Month::January,
            "February" => Month::February,
            "March" => Month::March,
            "April" => Month::April,
            "May" => Month::May,
            "June" => Month::June,
            "July" => Month::July,
            "August" => Month::August,
            "September" => Month::September,
            "October" => Month::October,
            "November" => Month::November,
            "December" => Month::December,
            _ => panic!("Invalid month string: {}", month_str),
        };


        let year: u16 = parts[2].trim().parse().unwrap_or(0);

        Self { day, month, year, time: None }

    }

    fn has_time(&self) -> bool {
        if self.time.is_none() {
            return false;
        } else {
            return true;
        }
    }

    fn set_time(&mut self, time: Time) {
        self.time = Some(time);
    }

    fn clear_time(&mut self) {
        self.time = None;
    }

}




impl PartialEq for Date {
    fn eq(&self, other: &Self) -> bool {
        self.year == other.year &&
        self.month == other.month &&
        self.day == other.day
    }
}

impl PartialOrd for Date {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Date {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.year != other.year {
            return self.year.cmp(&other.year);
        }

        if self.month != other.month {
            return self.month.cmp(&other.month);
        }

        if self.day != other.day {
            return self.day.cmp(&other.day);
        }

        if self.has_time() && other.has_time() {
            return self.time.cmp(&other.time)
        }

        Ordering::Equal
    }
}

#[derive(Debug, PartialEq, PartialOrd, Eq, Ord)]
enum Priority {
    Low = 1,
    Medium,
    High,
}

struct Task {
    name: String,
    description: String,
    priority: Priority,
    due: Date
}

impl Eq for Task {}

impl PartialEq for Task {
    fn eq(&self, other: &Self) -> bool {
        self.name == other.name &&
        self.description == other.description &&
        self.priority == other.priority &&
        self.due == other.due
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(&other))
    }
}

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.priority != other.priority {
            return self.priority.cmp(&other.priority);
        }

        self.due.cmp(&other.due)
        
    }
}




fn main() {
    use Priority::*;
    use Month::*;

    let task1 = Task {
        name: "Task 1".to_string(),
        description: "Opis zadania 1".to_string(),
        priority: Medium,
        due: Date::from_3(15, March, 2024),
    };

    let mut task2 = Task {
        name: "Task 2".to_string(),
        description: "Opis zadania 2".to_string(),
        priority: High,
        due: Date::from_3(10, March, 2024),
    };

    let mut task3 = Task {
        name: "Task 3".to_string(),
        description: "Opis zadania 3".to_string(),
        priority: Medium,
        due: Date::from_3(10, March, 2024),
    };

    // Dodajmy do tasków trochę czasu, żeby sprawdzić, czy time też działa
    task2.due.set_time(Time::from_3(9, 0, 0));  // 9:00:00
    task3.due.set_time(Time::from_3(8, 30, 0)); // 8:30:00

    let mut tasks = vec![task1, task2, task3];

    println!("Przed sortowaniem:");
    for t in &tasks {
        println!("{} - {:?} - due: {}", t.name, t.priority, t.due.to_string());
    }

    tasks.sort();

    println!("\nPo sortowaniu:");
    for t in &tasks {
        println!("{} - {:?} - due: {}", t.name, t.priority, t.due.to_string());
    }
}
