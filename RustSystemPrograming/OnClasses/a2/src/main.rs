// Zestaw 2a



fn f(x: f64) -> f64 {
    let temp1 = x - ((1.0 + 3.0.sqrt()) / 2);
    let temp2 = x + 200;
    return temp1 * temp2;
}

fn delta_f(x: f64) -> f64 {
    (2.0 * x) - 1.0
}


fn met_newt_for(x0: f64, eps: f64, n: u128) -> f64 {
    let mut x_n = x0;
    for i in 0..n {
        let x_n1 = x_n - (f(x_n) / delta_f(x_n));
        let temp = x_n1 - x_n;
        if(temp.abs() < eps) {
            return x_n1;
        }
        x_n = x_n1;
    }
    x_n
}

fn met_newt_loop(x0: f64, eps: f64, n: u128) -> f64 {
    let mut x_n = x0;
    let mut iterations = 0;

    loop {
        let x_n1 = x_n - (f(x_n) / delta_f(x_n));
        let temp = x_n1 - x_n;

        if iterations > n || temp.abs() < eps {
            break;
        }

        x_n = x_n1;
        iterations += 1;
    }

    x_n
}

fn met_newt_while(x0: f64, eps: f64, n: u128) -> f64 {
    let mut x_n = x0;
    let mut iterations = 0;

    while iterations < n {
        let x_n1 = x_n - (f(x_n) / delta_f(x_n));
        let temp = x_n1 - x_n;

        if temp.abs() < eps {
            return x_n1;
        }

        x_n = x_n1;
        iterations += 1;
    }

    x_n
}


fn met_newt_recur(x0: f64, eps: f64, n: u128, i: u128) -> f64 {
    let x_n = x0;

    let x_n1 = x_n - (f(x_n) / delta_f(x_n));

    let temp = x_n1 - x_n;

    if temp.abs() < eps || i == n {
        x_n1
    } else {
        met_newt_recur(x_n1, eps, n, i + 1)
    }
}


fn main() {
    let x0 = 2.0;
    let eps = 0.0001;
    let n = 100000;

    let result = met_newt_recur(x0, eps, n, 0);

    println!("Result of newton {}", result);
    println!("Function of result {}", f(result));
}