use std::io::{self, Write};
use rand::seq::SliceRandom;
use rand::thread_rng;

#[derive(Debug, Clone, Copy)]
enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades,
}

impl Suit {
    fn symbol(&self) -> char {
        match self {
            Suit::Hearts => '♥',
            Suit::Diamonds => '♦',
            Suit::Clubs => '♣',
            Suit::Spades => '♠',
        }
    }
}

#[derive(Debug, Clone, Copy)]
enum Value {
    Num(u8),
    Jack,
    Queen,
    King,
    Ace,
}

impl Value {
    fn points(&self) -> u8 {
        match self {
            Value::Num(n) => *n,
            Value::Jack | Value::Queen | Value::King => 10,
            Value::Ace => 11,
        }
    }

    fn as_str(&self) -> String {
        match self {
            Value::Num(n) => n.to_string(),
            Value::Jack => "J".to_string(),
            Value::Queen => "Q".to_string(),
            Value::King => "K".to_string(),
            Value::Ace => "A".to_string(),
        }
    }
}

#[derive(Debug, Clone, Copy)]
struct Card {
    suit: Suit,
    value: Value,
}

impl Card {
    fn as_str(&self) -> String {
        format!("{}{}", self.value.as_str(), self.suit.symbol())
    }
}

struct Deck {
    cards: Vec<Card>,
}

impl Deck {
    fn new() -> Self {
        let mut cards = Vec::new();
        for &suit in &[Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades] {
            for n in 2..=10 {
                cards.push(Card { suit, value: Value::Num(n) });
            }
            cards.push(Card { suit, value: Value::Jack });
            cards.push(Card { suit, value: Value::Queen });
            cards.push(Card { suit, value: Value::King });
            cards.push(Card { suit, value: Value::Ace });
        }
        let mut rng = thread_rng();
        cards.shuffle(&mut rng);
        Self { cards }
    }

    fn draw(&mut self) -> Option<Card> {
        self.cards.pop()
    }
}

struct Hand {
    cards: Vec<Card>,
}

impl Hand {
    fn new() -> Self {
        Self { cards: Vec::new() }
    }

    fn add(&mut self, card: Card) {
        self.cards.push(card);
    }

    fn points(&self) -> u8 {
        let mut total = 0;
        let mut aces = 0;
        for card in &self.cards {
            total += card.value.points();
            if let Value::Ace = card.value {
                aces += 1;
            }
        }
        while total > 21 && aces > 0 {
            total -= 10;
            aces -= 1;
        }
        total
    }

    fn display(&self) {
        for card in &self.cards {
            print!("{} ", card.as_str());
        }
        println!("-> {} pkt", self.points());
    }
}

fn prompt(msg: &str) -> String {
    print!("{}", msg);
    io::stdout().flush().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    println!("Gra w oczko - wersja dla 2 graczy\n");

    loop {
        let mut deck = Deck::new();
        let mut hand1 = Hand::new();
        let mut hand2 = Hand::new();

        hand1.add(deck.draw().unwrap());
        hand1.add(deck.draw().unwrap());

        hand2.add(deck.draw().unwrap());
        hand2.add(deck.draw().unwrap());

        println!("Gracz 1:");
        loop {
            hand1.display();
            if hand1.points() == 21 {
                println!("Gracz 1 ma oczko!");
                break;
            } else if hand1.points() > 21 {
                println!("Gracz 1 przegrał, ma ponad 21.");
                break;
            }

            let decision = prompt("Dobierasz kartę? (t/n): ");
            if decision == "t" {
                if let Some(card) = deck.draw() {
                    hand1.add(card);
                } else {
                    println!("Karty się skończyły!");
                    break;
                }
            } else {
                println!("Gracz 1 zatrzymuje się z {} punktami.", hand1.points());
                break;
            }
        }

        println!("\nGracz 2:");
        loop {
            hand2.display();
            if hand2.points() == 21 {
                println!("Gracz 2 ma oczko!");
                break;
            } else if hand2.points() > 21 {
                println!("Gracz 2 przegrał, ma ponad 21.");
                break;
            }

            let decision = prompt("Dobierasz kartę? (t/n): ");
            if decision == "t" {
                if let Some(card) = deck.draw() {
                    hand2.add(card);
                } else {
                    println!("Karty się skończyły!");
                    break;
                }
            } else {
                println!("Gracz 2 zatrzymuje się z {} punktami.", hand2.points());
                break;
            }
        }

        let p1 = hand1.points();
        let p2 = hand2.points();

        println!("\nWyniki końcowe:");
        println!("Gracz 1: {} pkt", p1);
        println!("Gracz 2: {} pkt", p2);

        let winner = match (p1 > 21, p2 > 21) {
            (true, true) => None,
            (true, false) => Some("Gracz 2"),
            (false, true) => Some("Gracz 1"),
            (false, false) => {
                if p1 > p2 { Some("Gracz 1") }
                else if p2 > p1 { Some("Gracz 2") }
                else { None }
            }
        };

        match winner {
            Some(w) => println!("Wygrywa {}!", w),
            None => println!("Remis!"),
        }

        let again = prompt("\nGracie dalej? (t/n): ");
        if again != "t" {
            println!("Dzięki za grę!");
            break;
        }
    }
}