#[derive(Debug)]
struct Matrix {
    matrix: Vec<Vec<f64>>,
}


impl Matrix {
    fn new(height: usize, width: usize, fill: f64) -> Self {
        let matrix = vec![vec![fill; width]; height];

        Self { matrix }
    }


    fn zerowa(height: usize, width: usize) -> Self {
        let matrix = vec![vec![0.0; width]; height];

        Self { matrix }
    }

    fn jednostkowa(height: usize) -> Self {
        let mut matrix = vec![vec![0.0; height]; height];
        
        for i in 0..height {
            matrix[i][i] = 1 as f64;
        }

        Self { matrix }
    }

    fn element(&self ,i: usize, j: usize) -> f64 {
        if i >= self.matrix.len() && j >= self.matrix[0].len() {
            return -6.9;
        } 

        return self.matrix[i][j];
    }

    fn zmien_element(&mut self, i: usize, j: usize, value: f64) {
        if i >= self.matrix.len() && j >= self.matrix[0].len() {
            return;
        } 

        self.matrix[i][j] = value;
    }

    fn suma(matrix1: &Self, matrix2: &Self) -> Option<Self> {
        if matrix1.matrix.len() != matrix2.matrix.len() {
            return None;
        }

        if matrix1.matrix[0].len() != matrix2.matrix[0].len() {
            return None;
        }

        let height =  matrix1.matrix.len();
        let width = matrix1.matrix[0].len();
        let mut result = Self::zerowa(height, width);

        for i in 0..height {
            for j in 0..width {
                result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
            }
        }

        Some( Self { matrix: result.matrix } )
    }

    fn wyswietl(&self) {
        for row in &self.matrix {
            for val in row {
              print!("{:8.2} ", val); // Ładny format z dwoma miejscami po przecinku
            }
            println!();
        }
    }
}   



fn main() {
    // Tworzymy macierz 2x3 zapełnioną 5.0
    let mac1 = Matrix::new(2, 3, 5.0);
    println!("Macierz 1:");
    mac1.wyswietl();

    // Zerowa macierz 2x3
    let mac2 = Matrix::zerowa(2, 3);
    println!("Macierz 2 (zerowa):");
    mac2.wyswietl();

    // Macierz jednostkowa 3x3
    let ident = Matrix::jednostkowa(3);
    println!("Macierz jednostkowa 3x3:");
    ident.wyswietl();

    // Odczyt elementu (0,1) w mac1
    println!("Element (0,1) mac1: {}", mac1.element(0, 1));

    // Odczyt elementu poza zakresem (10,10) w mac1
    println!("Element (10,10) mac1: {}", mac1.element(10, 10));

    // Modyfikacja elementu mac3
    let mut mac3 = Matrix::zerowa(2, 2);
    mac3.zmien_element(1, 1, 9.0);
    println!("Macierz mac3 po zmianie elementu (1,1) na 9.0:");
    mac3.wyswietl();

    // Suma macierzy mac1 + mac2 (pasują wymiary)
    match Matrix::suma(&mac1, &mac2) {
        Some(suma_macierzy) => {
            println!("Suma mac1 + mac2:");
            suma_macierzy.wyswietl();
        }
        None => println!("Nie można dodać macierzy o różnych wymiarach"),
    }

    // Próba sumy mac1 + mac4 (niepasujące wymiary)
    let mac4 = Matrix::new(3, 2, 1.0);
    match Matrix::suma(&mac1, &mac4) {
        Some(_) => println!("Coś tu nie halo, powinno się nie dać dodać!"),
        None => println!("Zgodnie z oczekiwaniem, macierze mają różne wymiary i nie można ich dodać"),
    }
}

