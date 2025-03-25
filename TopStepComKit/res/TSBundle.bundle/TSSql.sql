
/* 参数表 */
CREATE TABLE IF NOT EXISTS tsConfig (
    configID            VARCHAR NOT NULL,                   /* 参数Key */
    userID              VARCHAR,                            /* 用户ID */
    deviceID            VARCHAR,                            /* 设备ID */
    value               VARCHAR,                            /* 值 */
    ex1                 VARCHAR,                            /* 拓展信息1 */
    ex2                 VARCHAR,                            /* 拓展信息2 */
    desc                VARCHAR                             /* 描述 */
);

/* 心率图表数据表 */
CREATE TABLE IF NOT EXISTS tb_heart_rate (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    data                INT                                 /* 心率数据心率值(次/分钟) */
);

/* 静息心率数据表 */
CREATE TABLE IF NOT EXISTS tb_rest_heart_rate (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    data                INT                                 /* 静息心率数据 */
);

/* 步数图表数据表 */
CREATE TABLE IF NOT EXISTS tb_step (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    date                TEXT,                               /* ??? */
    time                TEXT,                               /* ??? */
    interval            INT,                                /* 采样时长(s) */
    data                BLOB,                               /* 步数图表数据 */
    allStep             INT,                                /* 总步数 */
    totalMileage        DOUBLE,                             /* 距离(cm) */
    totalConsumption    INT,                                /* ??? */
    duration            DOUBLE,                             /* 运动时长(分钟) */
    calory              INT                                 /* 卡路里(小卡) */
);

/* 压力图表数据表 */
CREATE TABLE IF NOT EXISTS tb_stress (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    date                TEXT,                               /* ??? */
    time                TEXT,                               /* ??? */
    interval            INT,                                /* ??? */
    data                BLOB,                               /* 压力图表数据 */
    maxValue            INT,                                /* ??? */
    minValue            INT,                                /* ??? */
    averageValue        INT                                 /* ??? */
);

/* 血氧饱和度图表数据表 */
CREATE TABLE IF NOT EXISTS tb_oxyhemoglobin_saturation (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    date                TEXT,                               /* ??? */
    time                TEXT,                               /* ??? */
    interval            INT,                                /* ??? */
    data                BLOB,                               /* 血氧饱和度图表数据 */
    maxValue            INT,                                /* ??? */
    minValue            INT,                                /* ??? */
    averageValue        INT                                 /* ??? */
);

/* 体重表 */
CREATE TABLE IF NOT EXISTS tb_weight (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    date                TEXT,                               /* ??? */
    weight              double                              /* 体重 */
);

/* 睡眠数据表 */
CREATE TABLE IF NOT EXISTS tb_sleep (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    record_time         INT,                                /* ??? */
    start_time          INT,                                /* ??? */
    type                INT,                                /* 睡眠类型 参考TPSHistorySleep_Type */
    duration            INT,                                /* 改为用秒做单位，否则会有误差 */
    belong_day          INT,                                /* 睡眠属于哪一天，秒级时间戳，取那天的0时 */
    data                BLOB                                /* 睡眠数据 */
);

/* 血压图表数据表 */
CREATE TABLE IF NOT EXISTS tb_blood_pressure (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           DOUBLE,                             /* 时间戳 */
    record_time         INT,                                /* ??? */
    sbp                 INT,                                /* 收缩压 */
    dbp                 INT,                                /* 舒张压 */
    data                BLOB                                /* 血压图表数据 */
);

/* 跑步运动信息 */
CREATE TABLE IF NOT EXISTS tb_sport_running (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           double,                             /* 时间戳 */
    sport_id            INT,                                /* ??? */
    type                INT,                                /* ??? */
    start_time          double,                             /* 运动开始时间戳 */
    duration            INT,                                /* 运动持续时间(秒) */
    step                INT,                                /* 步数 */
    data                BLOB                               /* 跑步运动信息图表数据 */
);

/* 轨迹表 */
CREATE TABLE IF NOT EXISTS tb_sport_location (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           double,                             /* 时间戳 */
    sport_id            INT,                                /* ??? */
    type                INT,                                /* ??? */
    longitude           DOUBLE,                             /* 经度 */
    latitude            DOUBLE,                             /* 纬度 */
    speed               DOUBLE,                             /* 速度 */
    duration            DOUBLE                              /* ??? */
);

/* 每公里配速表 */
CREATE TABLE IF NOT EXISTS tb_sport_speed_per_km (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           double,                             /* 时间戳 */
    sport_id            INT,                                /* ??? */
    speed               DOUBLE,                             /* 其实是配速(min/km)，其值与avgPace相同，只是为了兼容保持这个命名 */
    distance            DOUBLE,                             /* 距离(m) */
    startTimestamp      DOUBLE,                             /* ??? */
    endTimestamp        DOUBLE                              /* ??? */
);

/* 活动记录表 */
CREATE TABLE IF NOT EXISTS tb_activity_record (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    timestamp           double,                             /* 时间戳 */
    start_time          INT,                                /* ??? */
    data                BLOB                                /* ??? */
);


/* 跑步运动信息 添加运动心率 次/min */
ALTER TABLE [tb_sport_running] ADD [heartRate] INT NOT NULL DEFAULT 0;
/* 跑步运动信息 热量 小卡 */
ALTER TABLE [tb_sport_running] ADD [calorie] INT NOT NULL DEFAULT 0;
/* 泳姿   1: 自由泳 2:蛙泳 3:仰泳 4:蝶泳 */
ALTER TABLE [tb_sport_running] ADD [swimStyle] INT NOT NULL DEFAULT 1;
/* 游泳趟数 */
ALTER TABLE [tb_sport_running] ADD [swimLaps] INT NOT NULL DEFAULT 0;
/* 游泳划水次数 */
ALTER TABLE [tb_sport_running] ADD [swimStrokes] INT NOT NULL DEFAULT 0;
/* 游泳划水频率 */
ALTER TABLE [tb_sport_running] ADD [swimStrokeFreq] INT NOT NULL DEFAULT 0;
/* 游泳效率 */
ALTER TABLE [tb_sport_running] ADD [swolf] INT NOT NULL DEFAULT 0;
/* 跳绳-触发次数 */
ALTER TABLE [tb_sport_running] ADD [jumpCount] INT NOT NULL DEFAULT 0;
/* 跳绳-中断次数 */
ALTER TABLE [tb_sport_running] ADD [jumpBkCount] INT NOT NULL DEFAULT 0;
/* 跳绳-连续次数 */
ALTER TABLE [tb_sport_running] ADD [jumpConsCount] INT NOT NULL DEFAULT 0;
/* 椭圆机-触发次数 */
ALTER TABLE [tb_sport_running] ADD [elCount] INT NOT NULL DEFAULT 0;
/* 椭圆机-触发频率 */
ALTER TABLE [tb_sport_running] ADD [elFrequecy] INT NOT NULL DEFAULT 0;
/* 椭圆机-最大触发频率 */
ALTER TABLE [tb_sport_running] ADD [elMaxFrequecy] INT NOT NULL DEFAULT 0;
/* 椭圆机-最小触发频率 */
ALTER TABLE [tb_sport_running] ADD [elMinFrequecy] INT NOT NULL DEFAULT 0;
/* 划船机-触发次数 */
ALTER TABLE [tb_sport_running] ADD [rowCount] INT NOT NULL DEFAULT 0;
/* 划船机-触发频率 */
ALTER TABLE [tb_sport_running] ADD [rowFrequecy] INT NOT NULL DEFAULT 0;
/* 划船机-最大触发频率 */
ALTER TABLE [tb_sport_running] ADD [rowMaxFrequecy] INT NOT NULL DEFAULT 0;
/* 划船机-最小触发频率 */
ALTER TABLE [tb_sport_running] ADD [rowMinFrequecy] INT NOT NULL DEFAULT 0;
/* 平均配速-指的是该运动到这一时刻为止的总时间除以总距离，单位(min/km) */
ALTER TABLE [tb_sport_speed_per_km] ADD [avgPace] INT NOT NULL DEFAULT 0;
/* 瞬时配速-指的是该运动在这一个duration里的时间除以距离，单位(min/km) */
ALTER TABLE [tb_sport_speed_per_km] ADD [instantPace] INT NOT NULL DEFAULT 0;


/* 运动心率表 */
CREATE TABLE IF NOT EXISTS tb_sport_heartrate (
    ID                  INTEGER PRIMARY KEY AUTOINCREMENT,  /* 数据ID */
    user_id             TEXT,                               /* 用户ID */
    device_mac          TEXT,                               /* 设备mac地址(设备ID) */
    sport_id            INT,                                /* 运动记录ID（时间戳） */
    heartrate           INT,                                /* 心率值 */
    timestamp           DOUBLE                              /* 心率采样时间（时间戳） */
);

