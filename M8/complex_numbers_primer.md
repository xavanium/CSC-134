# Complex Numbers — A Primer for ComplexLab Users

So you ran `./complexlab`, it asked you for a "real part" and an "imaginary part," it drew an arrow on a grid, and now there's a line at the bottom that says `|z| = 5.00`. This document explains what any of that means, assuming zero math background past "I have heard of the Pythagorean theorem."

---

## 1. What is a complex number?

A complex number is just **two regular numbers stuck together**. That's the whole secret.

We call the two numbers the **real part** and the **imaginary part**, and we write them like this:

```
3 + 4i
```

- `3` is the real part.
- `4` is the imaginary part.
- The `i` is a label that says "this number is the imaginary one."

ComplexLab prompts you for these two numbers separately:

```
Real part (or 'q' to quit): 3
Imaginary part: 4
```

…and the result is the complex number `3 + 4i`.

That's it. If someone tries to make this scarier, they're showing off.

---

## 2. Why "imaginary"? Is that part fake?

It's a bad name, historically. Mathematicians in the 1500s were solving equations that needed the square root of a negative number to work, which wasn't supposed to be a thing. They called those values "imaginary" as an insult, then later realized they were extremely useful and the name stuck.

The short version:

- **Real numbers** are the ones on a regular number line: `-2, 0, 1.5, 7, π`.
- **Imaginary numbers** are real numbers multiplied by `i`, where `i` is defined as `√-1`.
- **Complex numbers** are one of each, added together: `(real) + (imaginary)i`.

For ComplexLab you don't need to think about `i = √-1` at all. Just treat the imaginary part as "the second coordinate."

---

## 3. The Argand plane (the grid ComplexLab draws)

Once you have two numbers per value, you can plot them on a 2D grid:

- The **horizontal axis** is the real part.
- The **vertical axis** is the imaginary part.

This grid is called the **complex plane** or the **Argand plane** (after Jean-Robert Argand, who popularized it in 1806). It's exactly the same idea as plotting `(x, y)` points in algebra class — just with new names for the axes.

When ComplexLab draws this:

```
  Im
                              ^
                              |
                              |          *
                              |       . .
                              |    . .
                              | . .
  ----------------------------+----------------------------> Re
                              |
                              |
                              |
                              |
```

- `Re` is the real axis (across).
- `Im` is the imaginary axis (up).
- The `+` is the origin, `0 + 0i`.
- The dotted line is the **vector** from the origin to your number.
- The `*` is your number itself.

So the picture above is `3 + 4i`: three units right, four units up.

---

## 4. What's `|z| = 5.00`? (the magnitude)

Below the plot, ComplexLab prints something like:

```
[*] 3.00 + 4.00i   |z| = 5.00
```

The `|z|` is the **magnitude** of the complex number — basically, "how long is the arrow?"

It's just the Pythagorean theorem applied to the two parts:

```
|z| = √(real² + imaginary²)
    = √(3² + 4²)
    = √(9 + 16)
    = √25
    = 5
```

That's why `3 + 4i` shows `|z| = 5.00`. The arrow is 5 units long.

A few magnitudes you can sanity-check yourself:

| Number | Magnitude |
|---|---|
| `1 + 0i`    | 1.00 |
| `0 + 1i`    | 1.00 |
| `3 + 4i`    | 5.00 |
| `-3 + -4i`  | 5.00 (direction changes, length doesn't) |
| `0 + 0i`    | 0.00 |

---

## 5. There's also an angle (the argument)

Every arrow on the plane has two things: a length and a direction. The length is the magnitude. The direction — measured as an angle counterclockwise from the positive real axis — is called the **argument** of the complex number.

ComplexLab computes this internally (`ComplexNumber::argument()` in the source), but the v2 build doesn't display it. If you wanted to see the angle for `3 + 4i`, it's about 53° (or 0.927 radians). For `0 + 1i` it's 90°. For `-1 + 0i` it's 180°.

You can ignore arguments entirely and still get plenty out of ComplexLab — but if you ever wonder "why is that arrow pointing *that way*," the argument is the answer.

---

## 6. How to read what ComplexLab shows you

Try this sequence in the program:

```
Real part: 3
Imaginary part: 4
```

You should see:

- A `*` somewhere in the upper-right area of the grid.
- A dotted line from the center to that `*`.
- A legend line: `[*] 3.00 + 4.00i   |z| = 5.00`.

Now add another:

```
Real part: -2
Imaginary part: 1
```

The grid redraws with **both** arrows. Each entry gets its own legend line. The plot **auto-scales** so the biggest arrow still fits, which means smaller arrows may look shorter than before — that's expected.

### What the axes tell you

- Anything **right** of the vertical axis has a positive real part.
- Anything **left** of it has a negative real part.
- Anything **above** the horizontal axis has a positive imaginary part.
- Anything **below** it has a negative imaginary part.

So the four quadrants correspond to the four sign combinations:

```
        Im
         ^
    -+iI | +R+iI
   (-,+) | (+,+)
  -------+------> Re
   (-,-) | (+,-)
    -R-iI| +R-iI
```

---

## 7. Things to try

Once you have the basics, here are some inputs that show off interesting behavior:

- **A right triangle:** enter `3, 0`, then `0, 4`, then `3, 4`. Two legs and a hypotenuse.
- **Same magnitude, different angles:** enter `5, 0`, `0, 5`, `-5, 0`, `0, -5`. All have `|z| = 5.00`.
- **The unit circle:** enter `1, 0`, then `0, 1`, then `-1, 0`, then `0, -1`. Four arrows of length 1 pointing at the four cardinal directions.
- **A tiny number next to a giant one:** enter `1, 1`, then `100, 100`. Watch the auto-scaler squash the first one near the origin.
- **The origin itself:** enter `0, 0`. You get a marker at the center and no arrow (length 0).

---

## 8. A glossary, for quick reference

| Term | What it means in ComplexLab |
|---|---|
| Complex number | A pair `(real, imaginary)`, written `a + bi`. |
| Real part | The first number you type. Horizontal axis. |
| Imaginary part | The second number you type. Vertical axis. |
| `i` | The unit imaginary number (`√-1`). You never type this; it's implied. |
| Argand plane | The 2D grid the program draws. Real = horizontal, Imag = vertical. |
| Magnitude (`|z|`) | The length of the arrow. `√(real² + imag²)`. |
| Argument | The angle of the arrow (computed, not displayed in v2). |
| Origin | The center of the plot. The complex number `0 + 0i`. |
| Vector | The arrow from the origin to your number. |

---

## 9. That's actually it

Complex numbers feel mysterious for about ten minutes and then they're just "two-number numbers." Everything ComplexLab does is some variation on:

1. Take a pair of numbers from you.
2. Plot it on a 2D grid.
3. Tell you how far it is from the center.

If you can read a road map, you can read this program's output.
