// Obtén el canvas y su contexto
const canvas = document.getElementById('backgroundCanvas');
const ctx = canvas.getContext('2d');

// Ajusta el tamaño del canvas al tamaño de la ventana
function resizeCanvas() {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
}
window.addEventListener('resize', resizeCanvas);
resizeCanvas();

// Variables para las partículas
let points = [];

// Crea partículas flotantes
function createParticles(num) {
    points = [];
    for (let i = 0; i < num; i++) {
        points.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height,
            vx: (Math.random() - 0.5) * 1, // Velocidad en X
            vy: (Math.random() - 0.5) * 1, // Velocidad en Y
            radius: Math.random() * 3 + 1, // Tamaño aleatorio
            alpha: Math.random() * 0.5 + 0.5 // Transparencia aleatoria
        });
    }
}
createParticles(150);

// Dibuja las partículas
function drawParticles() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    points.forEach(point => {
        ctx.beginPath();
        ctx.arc(point.x, point.y, point.radius, 0, Math.PI * 2);
        ctx.fillStyle = `rgba(0, 100, 0, ${point.alpha})`; // Color verde oscuro con transparencia
        ctx.fill();
    });
}

// Actualiza las partículas
function updateParticles() {
    points.forEach(point => {
        point.x += point.vx;
        point.y += point.vy;

        // Rebota en los bordes
        if (point.x < 0 || point.x > canvas.width) point.vx *= -1;
        if (point.y < 0 || point.y > canvas.height) point.vy *= -1;
    });
}

// Animación de las partículas
function animateParticles() {
    drawParticles();
    updateParticles();
    requestAnimationFrame(animateParticles);
}
animateParticles();