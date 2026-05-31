# EscapeFromCrystalia — Side-Scrolling Bullet-Hell Prototype (BP/C++ & Shaders)

A fast-paced, side-scrolling bullet-hell shooter built in UE5.7. This project serves as a technical showcase for combining robust BP/C++ gameplay architecture with procedural, textureless material shaders.

## 🚀 Key Features Implemented
* **Textureless Procedural Visuals:** Designed 100% of the game's visuals using math-driven, dynamic materials (noise nodes, sine waves, and vector math) to completely eliminate texture memory overhead.
* **Advanced Material Shaders:** Developed a dynamic water-mimicking background material with flowing distortion effects and translucent, refractive crystalline shaders for enemy models.
* **Procedural Runtime Level Generation:** Engineered an endless, seed-based level generator (visible via the UI seed tracker) that dynamically constructs obstacles as the player advances.
* **Seed-Based C++ Spawner:** Engineered a native C++ backend for the procedural spawner that uses seed-based algorithms to dictate wave generation rules.
* **Blueprint Object Pooling**: Developed an efficient, lightweight Object Pooling framework in Blueprints to handle high-volume bullet-hell projectiles without performance degradation.
* **Enhanced Input System:** Fully integrated UE5's native Enhanced Input for fluid character controls.

## 💾 Playable Build
You can download and test the compiled, production-ready build of the game here: [Google Drive Download Link](https://drive.google.com/drive/folders/1S3C8rG_6fVzUoIhHLkY7x-a1dhVFBZEy?usp=sharing) (Unzip the .zip archive after downloading)

## 🛠️ Tech Stack & Concepts
* Unreal Engine 5.7 (C++ & Material Editor)
* Procedural Shaders & Material Math (Textureless Workflow)
* Object Pooling & Memory Optimization
* Vector Math & Seed-Based Generation
