#[derive(PartialEq)]
enum Unit {
    Pieces(u32),
    Liters(f32),
    Kilograms(f32)
}

impl Unit {
    fn get_value(&self) -> f32 {
        match self {
            Unit::Pieces(val) => *val as f32,
            Unit::Liters(val) => *val,
            Unit::Kilograms(val) => *val
        }
    }
}

#[derive(PartialEq)]
enum Storage {
    Freezer,
    Fridge,
    Normal
}
#[derive(PartialEq)]
struct Towar {
    name: String,
    unit: Unit,
    unit_mass : f32,
    storage: Storage
}


impl Towar {
    fn new(name: String, unit: Unit, unit_mass: f32, storage: Storage) -> Result<Self, String> {
        if unit.get_value() < 0.0 {
            return Err("Ujemna waga".to_string());
        }

        let unit_mass = match unit {
            Unit::Kilograms(_) => 1.0,
            _ => unit_mass
        };

        Ok(Towar { name, unit, unit_mass, storage })
    }

    fn same_kind(&self, other: &Towar) -> bool {
        self == other
    }

fn add_quantity(&mut self, amount: f32) -> Result<(), String> {
    if amount <= 0.0 {
        return Err("Ilość musi być dodatnia".to_string());
    }

    match &mut self.unit {
        Unit::Pieces(val) => {
            if amount.fract() != 0.0 {
                return Err("Ilość sztuk musi być całkowita".to_string());
            }
            *val += amount as u32;
        }
        Unit::Liters(val) | Unit::Kilograms(val) => {
            *val += amount;
        }
    }

    Ok(())
}

}

struct Zamowienie {
    towary: Vec<Towar>,
}

impl Zamowienie {
    fn new() -> Self {
        Zamowienie { towary: Vec::new() }
    }

    fn weight(&self) -> f32 {
        self.towary
            .iter()
            .map(|product| product.unit.get_value() * product.unit_mass)
            .sum()
    }

    fn weight_by_storage(&self, storage: Storage) -> f32 {
        self.towary
            .iter()
            .filter(|product| product.storage == storage)
            .map(|product| product.unit.get_value() * product.unit_mass)
            .sum()
    }


    fn add(&mut self, new_item: Towar) -> Result<(), String> {
        let amount = new_item.unit.get_value();

        if amount <= 0.0 {
            return Err("Ilość musi być dodatnia".to_string());
        }

        for existing in &mut self.towary {
            if existing.same_kind(&new_item) {
                return existing.add_quantity(amount);
            }
        }

        // nie znaleziono – dodaj jako nowy towar
        self.towary.push(new_item);
        Ok(())
    }
    

}

fn main() {
    let mut zam = Zamowienie::new();

    let mleko = Towar::new("Mleko".to_string(), Unit::Liters(1.0), 1.0, Storage::Fridge).unwrap();
    let mleko2 = Towar::new("Mleko".to_string(), Unit::Liters(2.0), 1.0, Storage::Fridge).unwrap();
    let jajka = Towar::new("Jajka".to_string(), Unit::Pieces(10), 0.07, Storage::Fridge).unwrap();

    zam.add(mleko).unwrap();
    zam.add(mleko2).unwrap();
    zam.add(jajka).unwrap();

    println!("Całkowita waga zamówienia: {:.2} kg", zam.weight());
}
