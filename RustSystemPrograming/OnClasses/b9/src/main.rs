use std::cmp::Ordering;

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
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

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct Time {
    hour: u8,
    minute: u8,
}

impl Time {
    fn to_string(&self) -> String {
        format!("{:02}:{:02}", self.hour, self.minute)
    }

    fn from_3(hour: u8, minute: u8) -> Self {
        Self { hour, minute }
    }

    fn from_string(string: &str, delim: char) -> Self {
        let parts: Vec<&str> = string.split(delim).collect();
        let hour = parts[0].parse().unwrap_or(0);
        let minute = parts[1].parse().unwrap_or(0);
        Self { hour, minute }
    }
}

impl PartialOrd for Time {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Time {
    fn cmp(&self, other: &Self) -> Ordering {
        (self.hour, self.minute).cmp(&(other.hour, other.minute))
    }
}

#[derive(Debug, Clone, PartialEq, Eq, Copy)]
struct Date {
    day: u8,
    month: Month,
    year: u16,
    time: Option<Time>,
}

impl Date {
    fn to_string(&self) -> String {
        let base = format!("{:02}-{:02}-{}", self.day, self.month as u8, self.year);
        if let Some(t) = self.time {
            format!("{} {}", base, t.to_string())
        } else {
            base
        }
    }

    fn from_3(day: u8, month: Month, year: u16) -> Self {
        Self {
            day,
            month,
            year,
            time: None,
        }
    }

    fn from_string(string: &str, delim: char) -> Self {
        let parts: Vec<&str> = string.split(delim).collect();
        let day = parts[0].parse().unwrap_or(1);
        let month: u8 = parts[1].parse().unwrap_or(1);
        let year = parts[2].parse().unwrap_or(1970);
        Self {
            day,
            month: unsafe { std::mem::transmute(month) },
            year,
            time: None,
        }
    }

    fn has_time(&self) -> bool {
        self.time.is_some()
    }

    fn set_time(&mut self, time: Time) {
        self.time = Some(time);
    }

    fn clear_time(&mut self) {
        self.time = None;
    }
}

impl PartialOrd for Date {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Date {
    fn cmp(&self, other: &Self) -> Ordering {
        let date_cmp = (self.year, self.month as u8, self.day)
            .cmp(&(other.year, other.month as u8, other.day));

        match date_cmp {
            Ordering::Equal => self.time.cmp(&other.time),
            _ => date_cmp,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
enum Priority {
    Low,
    Medium,
    High,
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Task {
    name: String,
    description: String,
    priority: Priority,
    due: Date,
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        match self.priority.cmp(&other.priority) {
            Ordering::Equal => self.due.cmp(&other.due),
            ord => ord,
        }
    }
}

fn main() {
    let time = Time::from_3(14, 30);
    let mut date1 = Date::from_3(20, Month::May, 2025);
    date1.set_time(time);

    let date2 = Date::from_string("19-05-2025", '-');

    let task1 = Task {
        name: String::from("Zrób coś sensownego"),
        description: String::from("Sarkastyczny komentarz tutaj"),
        priority: Priority::High,
        due: date1,
    };

    let task2 = Task {
        name: String::from("Nie rób nic"),
        description: String::from("Bo i tak się nie uda"),
        priority: Priority::Medium,
        due: date2,
    };

    println!("Task 1: {:?}", task1);
    println!("Task 2: {:?}", task2);
    println!("Czy task1 < task2? {}", task1 < task2);
    println!("Date1: {}", date1.to_string());
    println!("Date2: {}", date2.to_string());
    println!("Date1 has time? {}", date1.has_time());
    
    let mut date3 = date1.clone();
    date3.clear_time();
    println!("Date3 (bez czasu): {}", date3.to_string());
}
