```
Проект состоит из трёх модулей:
1)Модель Земли
2)Модель спутника
3)HTTP сервер
Сборка проекта:
!!!Перед сборкой проекта перенести файлы из папки satellite-simulator/data/magnetic в папку C:/User/ProgramData/GeographicLib/magnetic!!!
cmake -B build -S .
cmake --build build
Примеры запросов:
1)
curl -X POST http://localhost:8888/simulate \
-H "Content-Type: application/json" \
-d '{
  "tle": {
    "title": "GPS BIIR-2 (PRN 13)",
    "line1": "1 24876U 97035A   25295.37891929  .00000035  00000+0  00000+0 0  9998",
    "line2": "2 24876  55.8687 107.8776 0096151  56.8428 304.1040  2.00563333 20718"
  },
  "start_epoch_ms": 1696022400000,
  "duration_s": 600.0,
  "step_s": 60.0,
  "h_fail_km": 100
}'
2)
curl -X POST http://localhost:8888/simulate -H "Content-Type: application/json" -d '{
  "tle": {
    "title": "PROXIMA I",
    "line1": "1 43694U 18088E   24139.00585883  .10206033 -14958-5  54833-3 0  9991",
    "line2": "2 43694  84.9863 193.3607 0012302 259.8395 100.1524 16.41319836 30801"
  },
  "start_epoch_ms": 1696022400000,
  "duration_s": 600.0,
  "step_s": 60.0,
  "h_fail_km": 100

}'
3)
curl -X POST http://localhost:8888/simulate \
-H "Content-Type: application/json" \
-d '{
  "tle": {
    "title": "NOAA 1",
    "line1": "1 04793U 70106A   25296.10517712 -.00000024  00000+0  11617-3 0  9990",
    "line2": "2 04793 101.3746 335.8324 0031917  91.8694 291.7005 12.54046066 51097"
  },
  "start_epoch_ms": 1696022400000,
  "duration_s": 600.0,
  "step_s": 60.0,
  "h_fail_km": 100
}'
4)
curl -X POST http://localhost:8888/simulate \
-H "Content-Type: application/json" \
-d '{
  "tle": {
    "title": "STARLINK-1008",
    "line1": "1 44714U 19074B   25295.43799480  .00001034  00000+0  88303-4 0  9991",
    "line2": "2 44714  53.0544  87.2520 0001277  89.5341 270.5795 15.06395607 32791"
  },
  "start_epoch_ms": 1696022400000,
  "duration_s": 600.0,
  "step_s": 60.0,
  "h_fail_km": 100
}'
5)
curl -X POST http://localhost:8888/simulate \
-H "Content-Type: application/json" \
-d '{
  "tle": {
    "title": "LEMUR-1",
    "line1": "1 40044U 14033AL  25295.98143352  .00004560  00000+0  54451-3 0  9997",
    "line2": "2 40044  97.7577  86.7503 0050587 135.2256 225.3058 14.83786777 61027"
  },
  "start_epoch_ms": 1696022400000,
  "duration_s": 600.0,
  "step_s": 60.0,
  "h_fail_km": 100
}'
