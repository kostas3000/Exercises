const express = require('express')
const app = express()
const cors = require('cors')
const port = process.env.PORT || 7000

app.use(cors())
app.use(express.urlencoded({extended: false}))
app.use(express.json())

const roomRouter = require('./Routes/RoomRoutes.js')
app.use('/rooms', roomRouter)

const userRouter = require('./Routes/UserRoutes.js')
app.use('/auth', userRouter)

const bookingRouter = require('./Routes/BookingRoutes.js')
app.use('/bookings', bookingRouter)

app.get('/', (req,res) => {
    res.status(200).json({message: "Home Page"})
})

app.all('*', (req,res) => {
    res.status(404).json({message: "Page not found"})
})

app.listen(port, () => {
    console.log(`Server listening on port ${port}...`)
})
