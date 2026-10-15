#[derive(PartialEq)]
enum Unit {
    Pieces(u32),
    Liters(f32),
    Kilograms(f32),
}

impl Unit {
    fn get_value(&self) -> f32 {
        match self {
            Unit::Pieces(val) => *val as f32,
            Unit::Liters(val) => *val,
            Unit::Kilograms(val) => *val,
        }
    }
}

#[derive(PartialEq)]
enum Storage {
    Freezer,
    Fridge,
    Normal,
}

struct Product { name: String, unit: Unit, unit_mass: f32, storage: Storage,
}

impl Product {
    fn new(name: String, unit: Unit, unit_mass: f32, storage: Storage) -> Product {
        if unit.get_value() < 0.0 {
            panic!("Wartość mniejsza od zera");
        }

        let unit_mass = match unit {
            Unit::Kilograms(_) => 1.0, 
            _ => unit_mass,
        };

        Product {
            name,
            unit,
            unit_mass,
            storage,
        }
    }
}

struct Order {
    products: Vec<Product>,
}

impl Order {
    fn new() -> Order {
        Order { products: Vec::new() }
    }

    fn total_mass(&self) -> f32 {
        let mut sum: f32 = 0.0;
        for product in &self.products {
            sum += product.unit.get_value() * product.unit_mass;
        }
        sum
    }

    fn total_mass_by_storage(&self, storage: Storage) -> f32 {
        let mut sum: f32 = 0.0;

        for product in &self.products {
            if product.storage == storage {
                sum += product.unit.get_value() * product.unit_mass;
            }
        }
        sum
    }

    fn add_product(&mut self, new_product: Product, quantity: f32) {
        if quantity < 0.0 {
            return;
        }
        
    }
}

fn main() {
   
}
