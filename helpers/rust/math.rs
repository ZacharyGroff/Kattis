mod math {
  /* Calculates maximum area of any cyclic quadrilateral. */ 
  fn brahmagupta(a: f64, b: f64, c: f64, d: f64) -> f64 {
    let s = (a + b + c + d) / 2.;
    f64::sqrt((s - a) * (s - b) * (s - c) * (s - d))
  }
}
