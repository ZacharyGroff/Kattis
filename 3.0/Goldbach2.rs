fn main() {
  let tests = get_input_line::<u8>().unwrap()[0];
  let primes = get_primes();
  for _ in 0..tests {
    let input = get_input_line::<u16>().unwrap()[0];
    let results = get_representations(input, &primes);
    println!("{} has {} representation(s)", input, results.len());
    for result in results {
      println!("{}", result);
    }
    println!();
  }
}

fn get_input_line<T: std::str::FromStr>() -> Result<Vec<T>, <T as std::str::FromStr>::Err> {
  let mut input = String::new();
  let _ = std::io::stdin().read_line(&mut input);
  input.split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn sieve(ceil: u32) -> Vec<bool> {
  let mut primes = init_vec(ceil);

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
  vec.push(false);
  vec.push(false);
  for _ in 2..ceil+1 {
    vec.push(true);
  }

  vec
}

fn get_primes() -> Vec<u16> {
  let sieve_vec = sieve(32000);
  let mut primes: Vec<u16> = Vec::new();
  for (i, is_prime) in sieve_vec.iter().enumerate() {
    if *is_prime {
      primes.push(i as u16);
    }
  }

  primes
}

fn get_representations(n: u16, primes: &Vec<u16>) -> Vec<String> {
  let half = n / 2;
  let mut representations: Vec<String> = Vec::new();
  for prime1 in primes {
    if *prime1 > half {
      continue;
    }
    for prime2 in primes {
      if *prime2 < half {
        continue;
      }
      if *prime1 + *prime2 == n {
        representations.push(format!("{}+{}", *prime1, *prime2));
      }
    }
  }

  representations
}
