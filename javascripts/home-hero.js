function initTypewriters() {
  const typewriters = document.querySelectorAll(".tb-typewriter");

  typewriters.forEach((node) => {
    if (node.dataset.typewriterReady === "true") {
      return;
    }

    let phrases;

    try {
      phrases = JSON.parse(node.dataset.typewriter || "[]");
    } catch {
      phrases = [];
    }

    if (!phrases.length) {
      return;
    }

    const textNode = node.querySelector(".tb-typewriter__text");

    if (!textNode) {
      return;
    }

    node.dataset.typewriterReady = "true";

    let phraseIndex = 0;
    let charIndex = 0;
    let deleting = false;

    const type = () => {
      const current = phrases[phraseIndex];

      textNode.textContent = current.slice(0, charIndex);

      let delay = deleting ? 42 : 88;

      if (!deleting && charIndex < current.length) {
        charIndex += 1;
      } else if (!deleting && charIndex === current.length) {
        deleting = true;
        delay = 1800;
      } else if (deleting && charIndex > 0) {
        charIndex -= 1;
      } else {
        deleting = false;
        phraseIndex = (phraseIndex + 1) % phrases.length;
        delay = 260;
      }

      window.setTimeout(type, delay);
    };

    type();
  });
}

if (typeof document$ !== "undefined" && document$.subscribe) {
  document$.subscribe(initTypewriters);
} else {
  document.addEventListener("DOMContentLoaded", initTypewriters);
}
