/**
 * Botón "volver arriba" para PLEPER
 */

document.addEventListener("DOMContentLoaded", function () {
  // Crear el botón y añadirlo al DOM
  createBackToTopButton();

  // Función para manejar la visibilidad del botón
  function handleScroll() {
    const backToTopButton = document.querySelector(".back-to-top");

    // Si el usuario ha desplazado más de 300px, mostrar el botón
    if (window.scrollY > 300) {
      backToTopButton.classList.add("visible");
    } else {
      backToTopButton.classList.remove("visible");
    }

    // Actualiza el tamaño del botón dependiendo del tamaño de la ventana y el scroll
    updateBackToTopButtonSize();
  }

  // Escuchar eventos de scroll
  window.addEventListener("scroll", handleScroll);
  window.addEventListener("resize", handleScroll); // Asegura que se actualice al redimensionar

  // Llamada inicial para manejar el estado inicial
  handleScroll();
});

/**
 * Crea el botón de "volver arriba" y lo añade al documento
 */
function createBackToTopButton() {
  // Comprobar si el botón ya existe
  if (document.querySelector(".back-to-top")) {
    return;
  }

  // Crear elemento de botón
  const backToTopButton = document.createElement("button");
  backToTopButton.className = "back-to-top";
  backToTopButton.setAttribute("aria-label", "Volver arriba");
  backToTopButton.innerHTML = "&#9650;"; // Símbolo de flecha hacia arriba

  // Añadir el botón al final del body
  document.body.appendChild(backToTopButton);

  // Añadir funcionalidad de scroll suave al hacer clic
  backToTopButton.addEventListener("click", function () {
    // Usar scrollTo con animación suave
    window.scrollTo({
      top: 0,
      behavior: "smooth",
    });

    // Forzar que el tamaño del botón se actualice después del scroll
    setTimeout(updateBackToTopButtonSize, 300); // Espera un poco para que el scroll termine antes de aplicar el tamaño
  });
}

/**
 * Actualiza el tamaño del botón "Volver Arriba" según el tamaño de la pantalla y el scroll
 */
function updateBackToTopButtonSize() {
  const backToTopButton = document.querySelector(".back-to-top");

  // Si la pantalla es menor o igual a 768px, siempre mantener la escala de 1.5
  if (window.innerWidth <= 768) {
    backToTopButton.style.transform = "scale(1.5)"; // Escala mayor para móviles
  } else {
    // En pantallas mayores de 768px, mantener el tamaño normal (escala 1)
    backToTopButton.style.transform = "scale(1)"; // Escala normal en pantallas grandes
  }
}
