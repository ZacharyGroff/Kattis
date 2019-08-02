fn main() {
  let (largest, inputs) = get_inputs();
  let prime_vec = get_primes((largest*2) + 8350);
  for i in prime_vec {
    println!("{}", i);
  }
  for input in inputs {
    //pass ref here
    let closest_prime = find_closest_prime(n*2, primes);
    if is_prime(input) {
      println!("{}", closest_prime);
    } else {
      println!("{} ({} is not prime)", closest_prime, input);
    }
  }
}

fn get_inputs() -> (u32, Vec<u32>) {
  let mut largest: u32 = 0;
  let mut inputs: Vec<u32> = Vec::new();
  loop {
    let input = get_input_line();
    if input == 0 {
      break
    }

    if largest < input {
      largest = input;
    }

    inputs.push(input);
  }

  (largest, inputs)
}

fn get_input_line() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.trim().parse().expect("wanted a number")
}

fn get_primes(ceil: u32) -> Vec<bool> {
  let mut primes: Vec<bool> = init_vec(ceil);
  let mut p: u32 = 2;
  loop {
    if p*p > ceil {
      break;
    }

    if primes[p as usize] == true {
      let mut i: u32 = p*p;
      loop {
        if i > ceil {
          break;
        }
        primes[i as usize] = false;
        i += p;
      }
    }

    p += 1;
  }

  primes
}

fn init_vec(ceil: u32) -> Vec<bool> {
  let mut vec: Vec<bool> = Vec::new();
  for _ in 0..ceil+1 {
    vec.push(true);
  }

  vec
}

fn is_prime(n: u32) -> bool {
  true
}

fn find_closest_prime(n: u32, primes: Vec<u32>) -> u32 {
  0
}
